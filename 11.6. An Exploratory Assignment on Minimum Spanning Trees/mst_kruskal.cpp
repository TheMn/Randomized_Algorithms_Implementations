#include <bits/stdc++.h>
using namespace std;

ofstream output("result.csv");

/**
 * @brief A function that calculates a value based on the input n.
 * This function's purpose is likely tied to the specific exploratory assignment.
 * @param n An integer input.
 * @return A double value calculated based on n.
 */
double k(int n){
    return 0.04 + pow(0.992, n)/(pow(n, 0.05) * log(n)/log(4.5));
}

/**
 * @brief Represents an edge in a graph.
 * Contains the two vertices of the edge and its weight.
 * The struct uses member-wise initialization.
 */
struct Edge{
    int u, v; ///< The vertices of the edge.
    double weight; ///< The weight of the edge.

    /**
     * @brief Overloads the less than operator to compare edges by weight.
     * @param edge The other edge to compare to.
     * @return True if this edge's weight is less than the other edge's weight, false otherwise.
     */
    bool operator<(const Edge& edge){
        return weight < edge.weight;
    }
};

/**
 * @brief Finds the Minimum Spanning Tree of a graph using Kruskal's algorithm.
 * @param edges A vector of the edges in the graph.
 * @param n_vertices The number of vertices in the graph.
 * @return A tuple containing the total weight of the MST, the weight of the largest edge in the MST, and a vector of the edges in the MST.
 */
tuple<double, double, vector<Edge> > mst_kruskal(vector<Edge> edges, int n_vertices){
    vector<int> forest_label(n_vertices);
    iota(forest_label.begin(), forest_label.end(), 0);

    double total = 0, max_edge = -1;
    vector<Edge> mst;

    sort(edges.begin(), edges.end());

    for(auto edge: edges){
        if(forest_label[edge.u] != forest_label[edge.v]){
            total += edge.weight;
            mst.push_back(edge);

            if(edge.weight > max_edge)
                max_edge = edge.weight;

            int old_label = forest_label[edge.u],
                new_label = forest_label[edge.v];
            for(int vertex=0; vertex<n_vertices; vertex++){
                if(forest_label[vertex] == old_label)
                    forest_label[vertex] = new_label;
            }
        }
    }
    return make_tuple(total, max_edge, mst);
}

/**
 * @brief Runs a single test case for the MST algorithm.
 * Generates a random graph, runs Kruskal's algorithm, and writes the results to a CSV file.
 * @param test_size The number of vertices in the test graph.
 */
void make_test(int test_size){
    random_device randomDevice;
    default_random_engine generator(randomDevice());
    uniform_real_distribution<double> distribution(0.0, 1.0);

    vector<Edge> graph;

    for(int i=0; i<test_size; i++){
        for(int j=i+1; j<test_size; j++){
            double rnd = distribution(generator);
            if(rnd <= k(test_size))
                graph.push_back((Edge){i, j, rnd});

            // cerr << i << '-' << j << ": " << rnd << '\n';
        }
    }

    clock_t start = clock();
    auto result = mst_kruskal(graph, test_size);
    clock_t end = clock();

    // cerr << "~~~~~~~~~~~~~~~~~\n" <<
    //         "Total Cost: " << get<0>(result) <<
    //         "\nLargest Edge: " << get<1>(result) <<
    //         "\nEdges List:\n";
    // for(auto edge: get<2>(result))
    //     cerr << '\t' << edge.u << '-' << edge.v << " (" << edge.weight << ")\n";
    
    output << test_size << ',' <<
                get<0>(result) << ',' <<
                get<1>(result) << ',' <<
                static_cast<double>((end-start))/CLOCKS_PER_SEC << '\n'; // n, total, max, time
}

/**
 * @brief The main function to run the MST experiment.
 * @return 0 on successful execution.
 */
int main(){
    int n_test[]={16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192};
    for(auto test_size: n_test){
    // for(int test_size=2; test_size<=1024; test_size++){
        for(int i=0; i<20; i++){
            make_test(test_size);
        }
        cerr << test_size << " done.\n";
    }
}