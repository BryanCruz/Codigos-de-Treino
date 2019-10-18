#include <bits/stdc++.h>

#define n_rules 10

using namespace std;

string rules[n_rules] = {"tesoura papel", "papel pedra", "pedra lagarto", "lagarto spock", "spock tesoura", "tesoura lagarto", "lagarto papel", "papel spock", "spock pedra", "pedra tesoura"};

        char l1[1000];
        char l2[1000];

            char scenario1[1000], scenario2[1000];


int main (void ) {
    int t;
    scanf("%d", &t);

    while(t--) {
        scanf("%s %s", l1, l2);

        string winner = "empate";

        for (auto rule : rules) {

            sprintf(scenario1, "%s %s", l1, l2);
            sprintf(scenario2, "%s %s", l2, l1);
            
            if (strcmp(rule.c_str(), scenario1) == 0) {
                winner = "rajesh";
            } else if (strcmp(rule.c_str(), scenario2) == 0) {
                winner = "sheldon";
            }
        }

        printf("%s\n", winner.c_str());
    }

    return 0;
}