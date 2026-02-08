#include <stdio.h>

int main() {
    int frames, pages;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    int ref[pages], frame[frames], last_used[frames];
    int time = 0, page_faults = 0;

    printf("Enter reference string: ");
    for (int i = 0; i < pages; i++)
        scanf("%d", &ref[i]);

    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
        last_used[i] = -1;
    }

    for (int i = 0; i < pages; i++) {
        int page = ref[i];
        time++;

        int hit = 0;
        for (int j = 0; j < frames; j++) {
            if (frame[j] == page) {
                hit = 1;
                last_used[j] = time;
                break;
            }
        }

        if (!hit) {
            int pos = -1;

            // Check empty frame first
            for (int j = 0; j < frames; j++) {
                if (frame[j] == -1) {
                    pos = j;
                    break;
                }
            }

            // If no empty frame → find LRU
            if (pos == -1) {
                int min = last_used[0];
                pos = 0;
                for (int j = 1; j < frames; j++) {
                    if (last_used[j] < min) {
                        min = last_used[j];
                        pos = j;
                    }
                }
            }

            frame[pos] = page;
            last_used[pos] = time;
            page_faults++;
        }

        // Print frame contents
        printf("Frames: ");
        for (int j = 0; j < frames; j++)
            printf("%d ", frame[j]);
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", page_faults);

    return 0;
}
