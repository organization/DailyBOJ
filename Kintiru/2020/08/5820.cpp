#include <stdio.h>
#include <string.h>
#include <vector>
#include <utility>

typedef std::pair<int, int> pii;

#define MAX_N 200001
#define MAX_K 1000001

std::vector<pii> neighbor[MAX_N];

int N, K, H[MAX_N][2], L[MAX_N]; //default variables

int size[MAX_N]; // store size of nodes
int processed[MAX_N]; // store if nodes are processed (DFS)
int minimum_paths[MAX_K]; // Minimum paths to get length / stores length as value
int reachable_to[MAX_K]; // stores if the centroid is reachable to any node in K length
int centroid; // Variables used to calculate centroid
int processed_centroid; // book keeping centroids that has been processed

int answer;

/*
 * GOAL : GET INPUT
 */
void get_input() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N - 1; ++i) {
        scanf("%d %d %d", &H[i][0], &H[i][1], &L[i]);
    }
}

/*
 * GOAL : BUILD TREE USING H, L
 */
void build_tree() {
    for(int i = 0; i < N - 1; ++i) {
        neighbor[H[i][0]].push_back(pii(H[i][1],L[i]));
        neighbor[H[i][1]].push_back(pii(H[i][0],L[i]));
    }
}

/*
 * GOAL : CALCULATE THE CENTROID;
 */
int get_centroid(int current, int parent, int total) {
    int i;
    for(i = 0; i < neighbor[current].size(); ++i) {
        if(!processed[neighbor[current][i].first] && neighbor[current][i].first != parent) {
            if(size[neighbor[current][i].first] > total)
                return get_centroid(neighbor[current][i].first, current, total);
        }
    }
    return current;
}

/*
 * GOAL : CALCULATE SIZE OF EACH NODE
 */
int calc_size(int current, int parent) {
    size[current] = 1;
    for(int i = 0; i < neighbor[current].size(); ++i){
        if(!processed[neighbor[current][i].first] && neighbor[current][i].first != parent) {
            size[current] += calc_size(neighbor[current][i].first, current);
        }
    }
    return size[current];
}

/*
 * GOAL : DFS CALCULATE ALL PATH FROM NODE
 */
void dfs_find_path (int current, int parent, int current_length, int past_roads) {

    if (current_length > K) return;

    int left_length = K - current_length;
    //when sharing same centroid
    if (reachable_to[left_length] == processed_centroid) {
        if(past_roads + minimum_paths[left_length] < answer || answer == -1 ) {
            answer = past_roads + minimum_paths[left_length];
        }
    }
    if (current_length == K) {
        if (answer > past_roads || answer == -1) {
            answer = past_roads;
        }
    }

    int i;
    for(i = 0; i < neighbor[current].size(); ++i) {
        if(!processed[neighbor[current][i].first] && neighbor[current][i].first != parent) {
            dfs_find_path(neighbor[current][i].first, current, current_length + neighbor[current][i].second, past_roads+1);
        }
    }
}

/*
 * GOAL : FILL ARRAYS THAT HELPS DFS
 */
void fill_dp_array(int current, int parent, int current_length, int past_roads) {

    if(current_length > K) return;

    // reset when root node is changed
    if(reachable_to[current_length] < processed_centroid) {
        reachable_to[current_length] = processed_centroid;
        // because this is only going to happen at first time, it's going to be minimum value
        minimum_paths[current_length] = past_roads;
    }
    else if (minimum_paths[current_length] > past_roads){
        reachable_to[current_length] = processed_centroid;
        minimum_paths[current_length] = past_roads;
    }

    int i;
    for(i = 0; i < neighbor[current].size(); ++i) {
        if(!processed[neighbor[current][i].first] && neighbor[current][i].first != parent) {
            fill_dp_array(neighbor[current][i].first, current, current_length + neighbor[current][i].second, past_roads+1);
        }
    }
}

/*
 * GOAL : PROCESS FROM CURRENT NODE ( PROCESS CENTROIDS )
 */
void process(int current) {
    // calculate the size of full tree
    calc_size(current,-1);

    // when there's only less than two nodes.
    if(size[current] <= 1) return;

    // get centroid
    centroid = get_centroid(current, -1, size[current] / 2);

    // need to be done before dfs to calculate best path
    processed_centroid++;

    // dfs search from centroid
    int i;
    for (i = 0; i < neighbor[centroid].size(); ++i) {
        if (!processed[neighbor[centroid][i].first]) {
            // brute force at first, and fill dp array with current node to help child node calculation.
            dfs_find_path(neighbor[centroid][i].first, centroid, neighbor[centroid][i].second, 1);
            fill_dp_array(neighbor[centroid][i].first, centroid, neighbor[centroid][i].second,1);
        }
    }

    //mark centroid as processed because the algorithm is divide&conquer
    processed[centroid] = 1;

    int local_centroid = centroid;
    for (i = 0; i < neighbor[local_centroid].size(); ++i) {
        if(!processed[neighbor[local_centroid][i].first]){
            process(neighbor[local_centroid][i].first);
        }
    }
}

/*
 * GOAL : GET ANSWER
 */
int best_path() {

    //set to answer when not found
    answer = -1;
    processed_centroid = 0;
    build_tree();
    process(0); // process from first node of tree

    return answer;
}

/*
 * GOAL : MAIN
 */
int main() {
    // reset arrays
    memset(size,0,sizeof(size));
    memset(processed,0,sizeof(processed));
    memset(minimum_paths,0,sizeof(minimum_paths));
    memset(reachable_to,0,sizeof(reachable_to));

    int ans;

    get_input();

    ans = best_path();
    printf("%d", ans);

    return 0;
}