# Q1. Show that $2n^2+n+1=O(n^2)$. Can you choose $c=2$?
We need $2n^2+n+n\leq cn^2$ by definition. That is, $n^2(2-c)+n+1\leq 0$. A direct condition for any $n\geq n_0$ is that $c \geq 2$. So we can't choose $c=2$, since the expression no longer will be parabolic and $n+1 \geq 0$. Now, the parabola will be upside down for $c >2$ then there always exists $n_0$ for $c>2$ where $n^2(2-c)+n+1$ is negative. Hence, the given equation is correct.
<br>
<br>

# Q2. If $f(n) = O(g(n))$ and $g(n)= O(h(n))$, then $f(n)=O(h(n))$. True or false?

By definiton, for some $n>n_1$, we have $f(n) \leq c_1 g(n)$ and  for some $n>n_2$, we have $g(n) \leq c_2 g(n)$. Which implies, $f(n) \leq c_1c_2h(n)$ and taking $max(n_1, n_2)$ we get out required $n_0$. True.
<br>
<br>

# Q3. If $f(n) = O(g(n))$, then $g(n)=O(f(n))$. True or false?
Contradictrory example given in class, $n=O(n^2)$
<br>
<br>

# Q4. Is $2^{n+1}=O(2^n)$?
$2.2^n \leq c .2^n$, clearly true for $c \geq 2$
<br>
<br>

# Q5. Is $2^{2n} = O(2^n)$?
Substituting $t = 2^{n}$, we get $t^2-ct \leq 0$.  This is never possible since for any $n \geq n_0$, the curve always grows upward as $t=2^n$ is monotoinically increasing function.
<br>
<br>

# Q6. ??
<br>
<br>


# Q7. Show that if $f(n)=O(g(n))$ and $f(n) = \Omega(g(n))$, then $f(n) = \Theta(g(n))$
Using same argument as done in Q2., for $max(n_1,n_2)$ and definition $c_2g(n) \leq f(n) \leq c_1g(n)$ is the requried expression.
