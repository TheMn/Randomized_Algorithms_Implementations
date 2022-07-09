#include <bits/stdc++.h>
using namespace std;

ofstream output("res.csv");

struct Edge{
    int u, v;
    double weight;

    bool operator<(const Edge& edge){
        return weight < edge.weight;
    }
};

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

void make_test(int test_size){
    random_device randomDevice;
    default_random_engine generator(randomDevice());
    uniform_real_distribution<double> distribution(0.0, 1.0);

    vector<Edge> graph;

    for(int i=0; i<test_size; i++){
        for(int j=i+1; j<test_size; j++){
            double rnd = distribution(generator);
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

int main(){
    // int n_test[]={16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192};
    // for(auto test_size: n_test){
    for(int test_size=1024; test_size<=1024; test_size++){
        for(int i=0; i<20; i++){
            make_test(test_size);
        }
        cerr << test_size << " done.\n";
    }
}