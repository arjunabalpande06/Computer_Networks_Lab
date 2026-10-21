
#include <stdio.h>

int main() {
    int bucket_size, n, rate, tokens = 0;
    int incoming, i, sent;

    printf("Token Bucket Algorithm Simulation\n");

    printf("Enter bucket size (capacity): ");
    scanf("%d", &bucket_size);

    printf("Enter token generation rate: ");
    scanf("%d", &rate);

    printf("Enter number of time units: ");
    scanf("%d", &n);

    if (bucket_size <= 0 || rate <= 0 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\nTime unit %d:\n", i + 1);

        tokens += rate;

        if (tokens > bucket_size) {
            tokens = bucket_size;
        }

        printf("Enter packets to send: ");
        scanf("%d", &incoming);

        if (incoming < 0) {
            printf("Invalid packet count.\n");
            return 1;
        }

        if (tokens >= incoming) {
            sent = incoming;
            tokens -= incoming;

            printf("Packets sent: %d\n", sent);
            printf("Packets dropped: 0\n");
        } else {
            sent = tokens;

            printf("Packets sent: %d\n", sent);
            printf("Packets dropped: %d\n",
                   incoming - sent);

            tokens = 0;
        }

        printf("Tokens remaining: %d\n", tokens);
    }

    printf("\nSimulation complete.\n");
    return 0;
}
