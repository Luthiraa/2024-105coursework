import sympy as sp
import math

# Define the symbolic variable theta
theta = sp.Symbol('theta')

# Define the two equations 
eq1 = 1 + 2*sp.sin(theta)
eq2 = math.sqrt(2) - 1

print('The two polar curve equations are:')
print('r =', sp.pretty(eq1)) 
print('r =', eq2)

print('\
Step 1: Set the equations equal to each other')
eq = sp.Eq(eq1, eq2)
print('Equation:', sp.pretty(eq))

print('\
Step 2: Solve the equation for theta')
sol = sp.solveset(eq, theta, domain=sp.Reals) 
print('Solutions for theta (in radians):', sol)

print('\
Step 3: Plug theta values into r equation to get r')
r_vals = [eq1.subs(theta, t) for t in sol]
print('r values at the intersection points:', r_vals)

print('\
Step 4: The points of intersection (r, theta) are:')
for r, t in zip(r_vals, sol):
    print(f'({r:.3f}, {t:.3f})')