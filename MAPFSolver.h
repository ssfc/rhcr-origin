#pragma once
#include "PBSNode.h"
#include "SIPP.h"
#include <ctime>

// Base class for MAPF solvers
class MAPFSolver
{
public:
    int k_robust;
    int window;
	bool hold_endpoints;

	double runtime;
    int screen;

	bool solution_found;
	double solution_cost;
	double avg_path_length;
	double min_sum_of_costs;
    vector<Path> solution;

	// initial data
	ReservationTable initial_rt;
	vector<Path> initial_paths;
    list< tuple<int, int, int> > initial_constraints; // <agent, location, timestep>
	list<const Path*> initial_soft_path_constraints; // the paths that all agents try to avoid
    // only this agent can stay in this location during before this timestep.
	unordered_map<int, double> travel_times;


	SingleAgentSolver& path_planner;
	// Runs the algorithm until the problem is solved or time is exhausted 
    virtual bool run(const vector<State>& starts,
            const vector< vector<int> >& goal_locations,
            int time_limit) = 0;


	MAPFSolver(const BasicGraph& G, SingleAgentSolver& path_planner);
	~MAPFSolver();

	// Save results
	virtual void save_results(const std::string &fileName, const std::string &instanceName) const = 0;
	virtual void save_search_tree(const std::string &fileName) const = 0;
	virtual void save_constraints_in_goal_node(const std::string &fileName) const = 0;
	virtual void clear() = 0;

	virtual string get_name() const = 0;

    const BasicGraph& G;
    vector<State> starts;
    vector< vector<int> > goal_locations;
    int num_of_agents;
	int time_limit;



    vector<vector<bool> > cat; // conflict avoidance table
    vector<unordered_set< pair<int, int> > > constraint_table;
    ReservationTable rt;

	// validate
	bool validate_solution();
};

