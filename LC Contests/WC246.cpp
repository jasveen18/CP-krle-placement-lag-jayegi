/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// 1. 1903. Largest Odd Number in String
class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        for (int i = n - 1; i >= 0; i--) {
            if ((num[i] - '0') & 1) {
                return num.substr(0, i + 1);
            }
        }

        return "";
    }
};


// 2. 1904. The Number of Full Rounds You Have Played
class Solution {
public:
    int numberOfRounds(string startTime, string endTime) {
        // Convert date and time to time.
        int startHr = (startTime[0] - '0') * 10 + (startTime[1] - '0');
        int startMin = (startTime[3] - '0') * 10 + (startTime[4] - '0');
        int endHr = (endTime[0] - '0') * 10 + (endTime[1] - '0');
        int endMin = (endTime[3] - '0') * 10 + (endTime[4] - '0');

        if (endHr - startHr == 0 and (endMin - startMin) < 15 and (endMin - startMin) >= 0)
            return 0;

        // Take ceil and floor of start time and end time resp.
        if (startMin > 0 and startMin < 15)
            startMin = 15;
        else if (startMin > 15 and startMin < 30)
            startMin = 30;
        else if (startMin > 30 and startMin < 45)
            startMin = 45;
        else if (startMin > 45 and startMin < 60) {
            startMin = 0;
            startHr += 1;

            // Case of midnight
            if (startHr == 24)
                startHr = 0;
        }

        if (endMin > 0 and endMin < 15)
            endMin = 0;
        else if (endMin > 15 and endMin < 30)
            endMin = 15;
        else if (endMin > 30 and endMin < 45)
            endMin = 30;
        else if (endMin > 45 and endMin < 60)
            endMin = 45;

        // Now, I want to count the intervals.
        int intervals = 0;
        while (startHr != endHr or startMin != endMin) {
            startMin += 15;
            if (startMin == 60) {
                startMin = 0;
                startHr += 1;

                if (startHr == 24)
                    startHr = 0;
            }
            intervals++;
        }

        return intervals;
    }
};



// 3. 1905. Count Sub Islands
void visitIslandDFS(vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>>& visited, int i, int j, bool &sub) {
    // Base Case -
    if (i < 0 or j < 0 or i >= grid2.size() or j >= grid2[0].size())
        return;

    if (grid2[i][j] == 0 or visited[i][j] == true)
        return;

    visited[i][j] = true;
    if (grid1[i][j] != 1 and grid2[i][j] == 1)
        sub = false;

    // Now from here, go to all it's neighbors
    int dx [] = {0, 1, -1, 0};
    int dy [] = {1, 0, 0, -1};

    for (int k = 0; k < 4; k++)
        visitIslandDFS(grid1, grid2, visited, i + dx[k], j + dy[k], sub);
}


int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int n = grid1.size();
    int m = grid1[0].size();

    // Approach -
    // 1. Try BFS / DFS with a visited array to find the island.
    // 2. Ek bool value bhi hoga if uss particular island pe grid1 ni hua toh false answer hai.

    vector<vector<bool>> visited(n, vector<bool> (m, false));
    int res = 0;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == false and grid2[i][j] == 1) {
                bool isSubIsland = true;
                visitIslandDFS(grid1, grid2, visited, i, j, isSubIsland);

                if (isSubIsland)
                    res++;
            }
        }
    }

    return res;
}


// 4. 1906. Minimum Absolute Difference Queries

// Approach -
// 1. We see that numbers are between 1 and 100.
// 2. We use seg tree with bitset array (seen ab tk) in each node.
// 3. The leaf represents a bitset with 1 at that position = value of num.
// 4. For range we will just do bitwise OR usse jo bhi elements hoga uske index pe 1 aa jayega.
// 5. Now, for each query we have a bitset array jisme jo jo elements hai uska index hai. So, we find the min gap.

// T - O(LogN * (100 + Q))

vector<bitset<101>> segTree;
vector<int> minDifference(vector<int> &nums, vector<vector<int>> &queries) {
    int n = nums.size();

    segTree = vector<bitset<101>> (4 * (n + 1) + 1);
    buildTree(1, 0, n - 1, nums);

    vector<int> ans;

    // Now process the queries
    for (int q = 0; q < queries.size(); q++) {
        auto seenArray = queryTree(1, 0, n - 1, queries[q][0], queries[q][1]);

        // Find the first 1
        int i = 0;
        while (i < 101 and seenArray[i] != 1)
            i++;

        int minGap = INT_MAX;
        int previousOne = i;

        // Now find the min gap
        for (int k = i + 1; k < 101; k++) {
            if (seenArray[k] == 1) {
                minGap = min(minGap, k - previousOne);
                previousOne = k;
            }
        }

        ans.push_back(minGap == INT_MAX ? -1 : minGap);
    }

    return ans;
}


void buildTree(int index, int start, int end, vector<int> &nums) {
    if (start > end)
        return;

    if (start == end) {
        bitset<101> b;
        b[nums[start]] = 1;

        segTree[index] = b;
        return;
    }

    // Build the range
    int mid = (start + end) / 2;
    buildTree(index * 2, start, mid, nums);
    buildTree(index * 2 + 1, mid + 1, end, nums);

    segTree[index] = segTree[2 * index] | segTree[2 * index + 1];
}


bitset<101> queryTree(int index, int start, int end, int queryStart, int queryEnd) {
    // Base Cases -
    if (start > end) return bitset<101>();
    // if out of range
    if (queryEnd < start or queryStart > end)
        return bitset<101>();

    // If complete range
    if (start >= queryStart and queryEnd >= end)
        return segTree[index];

    // If incomplete range
    int mid = (start + end) / 2;
    auto left = queryTree(index * 2, start, mid, queryStart, queryEnd);
    auto right = queryTree(index * 2 + 1, mid + 1, end, queryStart, queryEnd);

    return left | right;
}