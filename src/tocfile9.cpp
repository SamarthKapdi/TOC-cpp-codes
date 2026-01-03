#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int n_states, n_alpha;
    cout << "Samarth Kapdi, 0863CS231141" << endl;
    cout << "Enter number of states and alphabet count: ";
    cin >> n_states >> n_alpha;

    // 3D vector to store NDFA: [state][input][next_states]
    vector<vector<vector<int>>> ndfa(n_states, vector<vector<int>>(n_alpha));

    cout << "Enter transitions (state input next_state), -1 to stop:" << endl;
    while (true)
    {
        int s, i, next;
        cin >> s;
        if (s == -1)
            break;
        cin >> i >> next;
        ndfa[s][i].push_back(next);
    }

    // Store DFA states (mapped from set of NDFA states)
    map<vector<int>, int> dfa_map;
    vector<vector<int>> dfa_states;
    vector<int> start_node = {0}; // Assume start state is 0

    dfa_states.push_back(start_node);
    dfa_map[start_node] = 0;

    cout << "\n//~! DFA Transitions Table:\n";
    for (int i = 0; i < dfa_states.size(); i++)
    {
        // Iterate through inputs for current DFA state
        for (int j = 0; j < n_alpha; j++)
        {
            vector<int> new_set;
            // Union of reachable states
            for (int node : dfa_states[i])
            {
                for (int next : ndfa[node][j])
                {
                    bool exists = false;
                    for (int n : new_set)
                        if (n == next)
                            exists = true;
                    if (!exists)
                        new_set.push_back(next);
                }
            }
            sort(new_set.begin(), new_set.end());

            //~? Create new DFA state if not exists
            if (dfa_map.find(new_set) == dfa_map.end())
            {
                dfa_map[new_set] = dfa_states.size();
                dfa_states.push_back(new_set);
            }

            cout << "State " << i << " on input " << j << " -> State " << dfa_map[new_set] << endl;
        }
    }
    return 0;
}