#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> result;

bool isValid(const string& expr) {
    vector<char> stack;
    for (char ch : expr) {
        if (ch == '(') {
            stack.push_back(ch);
        } else if (ch == ')') {
            if (stack.empty()) {
                return false;
            }
            stack.pop_back();
        }
    }
    return stack.empty();
}

void backtrack(int index, int n, string current_expr, const vector<int>& a) {
    if (index == n) {
        if (isValid(current_expr)) {
            result.push_back(current_expr);
        }
        return;
    }

    if (a[index] == 0) {
        for (char ch : {'(', ')'}) {
            string new_expr = current_expr + ch;
            backtrack(index + 1, n, new_expr, a);
        }
    } else {
        char ch = (a[index] == 1) ? '(' : ')';
        string new_expr = current_expr + ch;
        backtrack(index + 1, n, new_expr, a);
    }
}

vector<string> generate_parentheses(int n, const vector<int>& a) {
    result.clear();
    backtrack(0, n, "", a);
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<string> result = generate_parentheses(n, a);

    for (const string& expr : result) 
	{
        for(int i = 0 ; i < expr.size() ; i++)
        	if (expr[i] == '(')
        		cout<<1;
        	else
        		cout<<2;
        cout<<' ';
	}

    return 0;
}
