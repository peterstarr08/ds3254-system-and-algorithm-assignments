# Calculating theoretical maximum input for 5 min rumtime

### Assumption:
Core Speed: $2.3\,\text{Ghz}$

## $O(n^2)$
For $5\,\text{ mins} = 300 \,\text{secs}$. We get number of instruction as $2.3\times10^9 \cdot 300 \,\text{excutions}$. Therefore, $\sqrt{2.3\times10^9 \cdot 300}$ is size of array. Thus, answer is array of size: $830,662$

## $O(n\log{n})$
Using same as above analysis. Since, there is no algebraic equation to this inverse, it can be approximated using https://lapets.io/pub/nlogn.pdf. Giving us: $2 \times 10^{10}$ size.

