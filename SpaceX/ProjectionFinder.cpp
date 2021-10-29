#include "ProjectionFinder.h"

#include <cmath>

#include "KramerProjectionSolver.h"
#include "LambdaParameter.h"
#include "NumericComparer.h"

namespace SpaceX
{
    SolutionStore ProjectionFinder::FindNearPointProjection(
        const FLine3D& line, const FPoint3D& input_point)
    {
        SolutionStore store;
        KramerProjectionSolver solver;
        store.m_projection = solver.CalculateProjection(line, input_point);
        store.m_lambda_parameter = LambdaParameter::CalculateLambda(line, store.m_projection);
        const auto distance = store.m_projection - input_point;
        store.m_length_projection_segment = std::sqrt((distance * distance).Sum());
        return store;
    }

    std::list<SolutionStore> ProjectionFinder::FindNearPointsProjection(
        const std::vector<FPoint3D>& poly_line, const FPoint3D& input_point)
    {
        assert(!poly_line.empty());

        const auto lines = GetLinesFromVectorPoints(poly_line);

        std::list<SolutionStore> solutions;
        size_t segment_number = 0;
        for (const auto& line : lines)
        {
            auto solution = FindNearPointProjection(line, input_point);
            solution.m_segment_number = ++segment_number;
            solutions.emplace_back(solution);
        }
        
        // find minimal distance to projection points
        const auto min_distance = *std::min_element(solutions.begin(), solutions.end(), 
            [](const SolutionStore& left, const SolutionStore& right) 
            {
                return NumericComparer::IsLess(left.m_length_projection_segment, right.m_length_projection_segment);
            });
        
        solutions.erase(std::remove_if(solutions.begin(), solutions.end(), 
            [min_distance](const SolutionStore& item) {
                return NumericComparer::IsLess(min_distance.m_length_projection_segment, item.m_length_projection_segment);
            }), solutions.end());
        
        // check if projection point is out of bound line segment
        for (auto& item : solutions)
        {
            if (NumericComparer::IsGreater(item.m_lambda_parameter, 1.f))
            {
                item.m_lambda_parameter = 1.f;
                item.m_projection = lines[item.m_segment_number].GetStartPoint();
            }
            if (NumericComparer::IsLess(item.m_lambda_parameter, 0.f))
            {
                item.m_lambda_parameter = 0.f;
                item.m_projection = lines[item.m_segment_number - 1].GetStartPoint();
            }
        }
        return solutions;
    }

    std::vector<FLine3D> ProjectionFinder::GetLinesFromVectorPoints(const std::vector<FPoint3D>& poly_line)
    {
        std::vector<FLine3D> lines;
        lines.reserve(poly_line.size() - 1);

        // init lines
        for (int i = 1; i < poly_line.size(); i++)
        {
            lines.push_back(FLine3D(poly_line[i - 1], poly_line[i]));
        }
        return lines;
    }
}