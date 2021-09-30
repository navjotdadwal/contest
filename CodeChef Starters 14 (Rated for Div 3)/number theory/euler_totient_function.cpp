// https://www.codechef.com/START14C/problems/TUPCOUNT

// problem reduced to euler totient function(phi)

ϕ(n)=ϕ(p1a1)⋅ϕ(p2a2)⋯ϕ(pkak)=(p1a1−p1a1−1)⋅(p2a2−p2a2−1)⋯(pkak−pkak−1)=pa11⋅(1−1p1)⋅pa22⋅(1−1p2)⋯pakk⋅(1−1pk)=n⋅(1−1p1)⋅(1−1p2)⋯(1−1pk)
 
  
// O(sqrt(n))
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

// O(log(log(n))) include in main() 
phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i < N; i++) phi[i] = i;
    for (int i = 2; i < N; i++) {
        if (phi[i] == i) {
            for (int j = i; j < N; j += i)
                phi[j] -= phi[j] / i;
        }
    }
