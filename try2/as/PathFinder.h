#pragma once
#include <vector>
#include "Vector3.h"

class PathFinding
{
	public :
		PathFinding(void);
		~PathFinding(void);th(vector)
		
		void FindPath(Vector3 currentPos,Vector3 targetPos);
		Vector3 NextPathPos();
		void ClearOpenList(){m_openList.clear();}
		void ClearVisitedList(){m_visitedList.clear();}
		void ClearPathToGoal(){m_partToGoal.clear();}
		bool m_intializedStartGoal;
		bool m_foundGoal
		
	private:
		void SetStartAndGoal(SeachCell start, searchCell goal)
		void PathOpened(int x,int z,float newCost,SearchCell *parent);
		SeachCell *GetNextCell();
		void ContinuePath();
		
		SearchCell *m_startCell;
		SearchCell *m_goalCell;
		std::vector<searchCell*>m_openList;
		std::vector<SearchCell*>m_VisitedList;
		std::vector<Vector3*>m_pathToGoal;
}
