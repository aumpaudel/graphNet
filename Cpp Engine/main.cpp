#include <iostream>
#include <vector>
#include <utility>
#include "graph.h"

using namespace std;

int main() {

    Graph g;

    cout << "========== ADD USERS ==========\n";

    cout << "Add User 1: "
         << g.addUser(1, "A") << '\n';

    cout << "Add User 2: "
         << g.addUser(2, "B") << '\n';

    cout << "Add User 3: "
         << g.addUser(3, "C") << '\n';

    cout << "Add User 4: "
         << g.addUser(4, "D") << '\n';

    cout << "Add User 5: "
         << g.addUser(5, "E") << '\n';


    cout << "\n========== EXIST ==========\n";

    cout << "User 1 exists: "
         << g.exist(1) << '\n';

    cout << "User 10 exists: "
         << g.exist(10) << '\n';


    cout << "\n========== ADD FRIENDS ==========\n";

    cout << "1 - 2: "
         << g.addFriend(1, 2) << '\n';

    cout << "1 - 3: "
         << g.addFriend(1, 3) << '\n';

    cout << "2 - 3: "
         << g.addFriend(2, 3) << '\n';

    cout << "2 - 4: "
         << g.addFriend(2, 4) << '\n';

    cout << "3 - 5: "
         << g.addFriend(3, 5) << '\n';

    cout << "4 - 5: "
         << g.addFriend(4, 5) << '\n';


    cout << "\n========== GRAPH ==========\n";

    g.printGraph();


    cout << "\n========== BFS ==========\n";

    vector<int> bfsResult = g.bfs(1);

    cout << "BFS from 1: ";

    for (int x : bfsResult) {
        cout << x << " ";
    }

    cout << '\n';


    cout << "\n========== DFS ==========\n";

    vector<int> dfsResult = g.dfs(1);

    cout << "DFS from 1: ";

    for (int x : dfsResult) {
        cout << x << " ";
    }

    cout << '\n';


    cout << "\n========== SHORTEST PATH ==========\n";

    auto pathResult = g.shortestPath(1, 5);

    cout << "Shortest path from 1 to 5: ";

    for (int x : pathResult.first) {
        cout << x << " ";
    }

    cout << "\nDistance: "
         << pathResult.second << '\n';


    cout << "\n========== MUTUAL FRIENDS ==========\n";

    vector<int> mutual = g.mutualFriends(1, 2);

    cout << "Mutual friends of 1 and 2: ";

    for (int x : mutual) {
        cout << x << " ";
    }

    cout << '\n';


    cout << "\n========== FRIEND RECOMMENDATIONS ==========\n";

    vector<int> recommendations = g.recommendFriends(1);

    cout << "Recommendations for user 1: ";

    for (int x : recommendations) {
        cout << x << " ";
    }

    cout << '\n';


    cout << "\n========== CONNECTED COMPONENTS ==========\n";

    vector<vector<int>> components = g.connectedComponents();

    cout << "Connected Components:\n";

    for (const auto& component : components) {

        cout << "{ ";

        for (int x : component) {
            cout << x << " ";
        }

        cout << "}\n";
    }


    cout << "\n========== COMPONENT COUNT ==========\n";

    cout << "Number of components: "
         << g.componentCount() << '\n';


    cout << "\n========== STATISTICS ==========\n";

    cout << "Total users: "
         << g.totalUsers() << '\n';

    cout << "Total connections: "
         << g.totalConnections() << '\n';

    cout << "Average friends: "
         << g.averageFriends() << '\n';

    cout << "Most connected user: "
         << g.mostConnectedUser() << '\n';


    cout << "\n========== REMOVE FRIEND ==========\n";

    cout << "Remove friendship 1 - 3: "
         << g.removeFriend(1, 3) << '\n';

    cout << "\nGraph after removing 1 - 3:\n";

    g.printGraph();


    cout << "\n========== REMOVE USER ==========\n";

    cout << "Remove user 5: "
         << g.removeUser(5) << '\n';

    cout << "\nGraph after removing user 5:\n";

    g.printGraph();


    cout << "\n========== FINAL STATISTICS ==========\n";

    cout << "Total users: "
         << g.totalUsers() << '\n';

    cout << "Total connections: "
         << g.totalConnections() << '\n';

    cout << "Average friends: "
         << g.averageFriends() << '\n';

    cout << "Most connected user: "
         << g.mostConnectedUser() << '\n';


    return 0;
}