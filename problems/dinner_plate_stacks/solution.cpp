class DinnerPlates {
public:
    set<int> s_aval;
vector<stack<int>> vs;
int cap = 0;
DinnerPlates(int capacity) { cap = capacity; }
void push(int val) {
  if (s_aval.empty()) {
    vs.push_back(stack<int>());
    s_aval.insert(vs.size() - 1);
  }
  auto idx = *s_aval.begin();
  vs[idx].push(val);
  if (vs[idx].size() == cap) s_aval.erase(s_aval.begin());
}
int pop() {
  if (vs.empty()) return -1;
  auto res = vs.back().top(); vs.back().pop();
  while (!vs.empty() && vs.back().empty()) {
    s_aval.erase(vs.size() - 1);
    vs.pop_back();
  }
  if (!vs.empty() && vs.back().size() < cap) s_aval.insert(vs.size() - 1);
  return res;
}
int popAtStack(int index) {
  if (vs.size() <= index || vs[index].empty()) return -1;
  if (vs.size() - 1 == index) return pop();
  auto res = vs[index].top(); vs[index].pop();
  s_aval.insert(index);
  return res;
}
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */