#include <bits/stdc++.h>
using namespace std;
#define MAX 1010
#define MAX_PEOPLE 1000000
queue<int> team[MAX];
queue<int> mainQueue;
bool teamInQueue[MAX];
int people[MAX_PEOPLE];
int teamNums, Scenario = 1;
void init()
{
	for (int i = 0; i < teamNums; ++i)
	{
		teamInQueue[i] = false;
		while (!team[i].empty())
			team[i].pop();
	}
	while (!mainQueue.empty())
		mainQueue.pop();
}
void input()
{
	int totalPeopleInTeam, peopleID;
	for (int teamIndex = 0; teamIndex < teamNums; ++teamIndex)
	{
		cin >> totalPeopleInTeam;
		for (int j = 0; j < totalPeopleInTeam; ++j)
		{
			cin >> peopleID;
			people[peopleID] = teamIndex;
		}
	}
}
void solve()
{
	int peopleID, teamID;
	string command;
	cout << "Scenario #" << Scenario++ << endl;
	while (cin >> command && command[0] != 'S')
	{
		if (command[0] == 'E')
		{
			cin >> peopleID;
			teamID = people[peopleID];
			if (teamInQueue[teamID])
			{
				team[teamID].push(peopleID);
			}
			else
			{
				teamInQueue[teamID] = true;
				mainQueue.push(teamID);
				team[teamID].push(peopleID);
			}
		}
		else
		{
			if (!mainQueue.empty())
			{
				teamID = mainQueue.front();
				cout << team[teamID].front() << endl;
				team[teamID].pop();
				if (team[teamID].empty())
				{
					teamInQueue[teamID] = false;
					mainQueue.pop();
				}
			}
		}
	}
	cout << endl;
}
int main()
{
	//	freopen("queueofteams.in","r",stdin);
	//	freopen("queueofteams.out","w",stdout);
	while (cin >> teamNums && teamNums)
	{
		init();
		input();
		solve();
	}
	return 0;
}
