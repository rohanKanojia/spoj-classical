#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
    int N;
    while(true) {
        scanf("%d", &N);
        if(N == 0) break;

        int gcdDimension = -1;
        std::vector<int> x, y, z;
        for(int i = 0; i < N; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);

            x.push_back(a);
            y.push_back(b);
            z.push_back(c);

            if(gcdDimension == -1)
                gcdDimension = a;
            else
                gcdDimension = std::__gcd(gcdDimension, a);
            gcdDimension = std::__gcd(gcdDimension, b);
            gcdDimension = std::__gcd(gcdDimension, c);
        }
 
        long long ans = 0;
        for(int i = 0; i < N; i++) 
            ans += ((x[i] / gcdDimension) * (y[i] / gcdDimension) * (z[i] / gcdDimension));
        printf("%lld\n", ans);
    }
}
