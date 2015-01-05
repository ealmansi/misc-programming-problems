// Problem: Transform The Expression
// 12320342 2014-09-07 05:27:53 emilio  Transform the Expression  accepted   edit  run 0.04  2.8M   C++ 4.3.2
// http://www.spoj.com/problems/ONP/

#include <cstdlib>
#include <iostream>
using namespace std;

#define repeat(n) for (int __i__ = 0; __i__ < (n); ++__i__)

void expression_to_rpn_aux(string& expr, int i, int j)
{
  if (i == j)
  {
    cout << expr[i];
  }
  else
  {
    ++i;--j;
    if ('0' <= expr[i] && expr[i] <= '9')
    {
      cout << expr[i];
      expression_to_rpn_aux(expr, i + 2, j);
      cout << expr[i+1];
    }
    else
    {
      int op_index = i, p_count = 0;

      do
      {
        if (expr[op_index] == '(') ++p_count;
        else if (expr[op_index] == ')') --p_count;
        ++op_index;
      } while(p_count != 0);

      expression_to_rpn_aux(expr, i, op_index - 1);
      expression_to_rpn_aux(expr, op_index + 1, j);
      cout << expr[op_index];
    }
  }
}

void expression_to_rpn(string& expr)
{
  expression_to_rpn_aux(expr, 0, expr.size() - 1);
  cout << endl;
}

int main(int argc, char const *argv[])
{
  int t;
  cin >> t;

  string expr; getline(cin, expr);
  repeat(t)
  {
    getline(cin, expr);
    expression_to_rpn(expr);
  }

  return 0;
}