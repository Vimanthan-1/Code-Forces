
#include <bits/stdc++.h>
using namespace std;

int n, limitSkill;
int ans = 0;

vector<int> skill;
vector<pair<int, int>> units;
vector<pair<int, int>> rivals;

void dfs(size_t idx, int count, int total,
         vector<bool>& selected) {

    if (total > limitSkill) return;

    if (idx == units.size()) {
        ans = max(ans, count);
        return;
    }

    // Option 1: Skip current unit
    dfs(idx + 1, count, total, selected);

    // Option 2: Select current unit
    int u = units[idx].first;
    int v = units[idx].second;

    vector<int> members = {u};

    if (v != -1)
        members.push_back(v);

    bool valid = true;

    for (auto [a, b] : rivals) {
        bool hasA = selected[a] ||
            find(members.begin(), members.end(), a) != members.end();

        bool hasB = selected[b] ||
            find(members.begin(), members.end(), b) != members.end();

        if (hasA && hasB) {
            valid = false;
            break;
        }
    }

    if (!valid) return;

    for (int p : members)
        selected[p] = true;

    int addedSkill = skill[u];
    int addedCount = 1;

    if (v != -1) {
        addedSkill += skill[v];
        addedCount++;
    }

    dfs(idx + 1, count + addedCount,
        total + addedSkill, selected);

    for (int p : members)
        selected[p] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    vector<string> names(n);

    for (auto& x : names)
        cin >> x;

    skill.resize(n);

    for (int& x : skill)
        cin >> x;

    unordered_map<string, int> id;

    for (int i = 0; i < n; i++)
        id[names[i]] = i;

    vector<bool> used(n, false);

    int n1;
    cin >> n1;

    for (int i = 0; i < n1; i++) {
        string a, b;
        cin >> a >> b;

        int u = id[a];
        int v = id[b];

        units.push_back({u, v});

        used[u] = used[v] = true;
    }

    for (int i = 0; i < n; i++) {
        if (!used[i])
            units.push_back({i, -1});
    }

    int n2;
    cin >> n2;

    for (int i = 0; i < n2; i++) {
        string a, b;
        cin >> a >> b;

        rivals.push_back({id[a], id[b]});
    }

    cin >> limitSkill;

    vector<bool> selected(n, false);

    dfs(0, 0, 0, selected);

    cout << ans << '\n';

    return 0;
}
