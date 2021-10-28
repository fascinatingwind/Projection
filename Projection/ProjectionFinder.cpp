#include "ProjectionFinder.h"

#include "KramerProjectionSolver.h"
#include "LambdaParameter.h"

namespace Projection
{
    SolutionStore ProjectionFinder::FindNearPointProjection(
        const FLine3D& line, const FPoint3D& input_point)
    {
        SolutionStore store;
        KramerProjectionSolver solver;
        store.m_projection = solver.CalculateProjection(line, input_point);
        store.m_lambda_parameter = LambdaParameter::CalculateLambda(line, input_point);
        
        // if lambda param is out of bound [0;1] than we take line points
        if (NumericComparer::IsGreater(store.m_lambda_parameter, 1.f))
        {
            store.m_projection = line.GetEndPoint();
        }
        else if (NumericComparer::IsLess(store.m_lambda_parameter, 0.f))
        {
            store.m_projection = line.GetStartPoint();
        }

        return store;
    }

    std::vector<SolutionStore> ProjectionFinder::FindNearPointsProjection(
        const std::vector<FPoint3D> poly_line, const FPoint3D& input_point)
    {
        std::vector<SolutionStore> solutions;
        solutions.reserve(poly_line.size());

        for (int i = 1; i < poly_line.size(); i++)
        {
            auto solution = FindNearPointProjection(
                FLine3D(poly_line[i - 1], poly_line[i]), input_point);
            solution.m_segment_number = i - 1;
            if(solution.m_lambda_parameter >= 0 && solution.m_lambda_parameter <= 1)
                solutions.emplace_back(solution);
        }

        return solutions;
    }
}