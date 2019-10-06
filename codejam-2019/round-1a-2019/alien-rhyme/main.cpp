#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

struct node {
    int qt;

    node* prox[26];
};

node* new_node() {
    node* n = (node*) malloc(sizeof(node));
    n->qt = 0;
    
    for (int i = 0; i < 26; i++) {
        n->prox[i] = NULL;
    }

    return n;
}

int char_to_i (char c) {
    return c - 'A';
}

int len(char* word) {
    int i;
    for (i = 0; word[i] != '\0'; i++) {

    }

    return i;
}

void update(node* n, int i) {
    if (n->prox[i] == NULL) {
        n->prox[i] = new_node();
    }

    n->prox[i]->qt++;
}

node* find_best_child (node* n) {
    node* best = NULL;

    for (int i = 0; i < 26; i++) {
        if (best == NULL || (n->prox[i] != NULL && n->prox[i]->qt > best->qt)) {
            best = n->prox[i];
        }
    }

    return best;
}

int calc (node* head) {
    if (head == NULL) {
        return 0;
    }
    
    int result = 0;
    
    int i = 0;
    while (head->qt > 1) {

        for (int j = 0; j < 2; j++) {
            while (head->prox[i] == NULL) i++;
            result += calc(head->prox[i]);
        }
    }

    return result;
}

void free_all (node* head) {
    if (head == NULL) {
        return;
    }

    for (int i = 0; i < 26; i++) {
        free_all(head->prox[i]);
    }

    free(head);
}

int main (void) {
	ios_base::sync_with_stdio(false);

    int t;
    int result;
    scanf("%d", &t);

    node* head;

    char word[60];

    int next_n;
    int nw;
    for (int T = 1; T <= t; T++) {
        head = new_node();
        scanf("%d", &nw);

        for (int j = 0; j < nw; j++) {
            scanf("%s", word);
            node* curr = head;

            for (int i = len(word)-1; i >= 0; i--) {
                next_n = char_to_i(word[i]);

                update(curr, next_n);

                curr = curr->prox[next_n];
            }
        }
        
        result = 0;
        for (int i = 0; i < 26; i++) {
            result += calc(head->prox[i]);
        }
        result *= 2;

        printf("Case #%d: %d\n", T, result);
        free_all(head);
    }

	return 0;
}
