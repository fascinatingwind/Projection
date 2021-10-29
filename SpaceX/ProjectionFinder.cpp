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

    std::vector<SolutionStore> ProjectionFinder::FindNearPointsProjection(
        const std::vector<FPoint3D>& poly_line, const FPoint3D& input_point)
    {
        assert(!poly_line.empty());

        std::vector<SolutionStore> solutions;
        solutions.reserve(poly_line.size());
       
        // find all solutions
        for (int i = 1; i < poly_line.size(); i++)
        {
            auto solution = FindNearPointProjection(
                FLine3D(poly_line[i - 1], poly_line[i]), input_point);
            solution.m_segment_number = i;
            solutions.emplace_back(solution);
        }
        
        const auto minimum_distance = std::min_element(solutions.begin(), solutions.end(),
            [](const SolutionStore& left, const SolutionStore& right) 
            { 
                return NumericComparer::IsLess(left.m_length_projection_segment, right.m_length_projection_segment); 
            });

        solutions.erase(std::remove_if(solutions.begin(), solutions.end(), 
            [minimum_distance](const SolutionStore& store) {
                return NumericComparer::IsLess(minimum_distance->m_length_projection_segment, store.m_length_projection_segment);
            }), solutions.end());

        return solutions;
    }
}