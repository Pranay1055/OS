#include <stdio.h>

int main() {
    int frames, pages;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    int ref[pages], frame[frames];
    int page_faults = 0;

    printf("Enter reference string: ");
    for (int i = 0; i < pages; i++)
        scanf("%d", &ref[i]);

    for (int i = 0; i < frames; i++)
        frame[i] = -1;

    for (int i = 0; i < pages; i++) {
        int page = ref[i];
        int hit = 0;

        // Check if page is already in frame
        for (int j = 0; j < frames; j++) {
            if (frame[j] == page) {
                hit = 1;
                break;
            }
        }

        if (!hit) {
            int pos = -1, farthest = -1;

            // Look for empty frame first
            for (int j = 0; j < frames; j++) {
                if (frame[j] == -1) {
                    pos = j;
                    break;
                }
            }

            // If no empty frame → find optimal victim
            if (pos == -1) {
                for (int j = 0; j < frames; j++) {
                    int next_use = -1;

                    for (int k = i + 1; k < pages; k++) {
                        if (frame[j] == ref[k]) {
                            next_use = k;
                            break;
                        }
                    }

                    if (next_use == -1) {   // Never used again
                        pos = j;
                        break;
                    }
                    else if (next_use > farthest) {
                        farthest = next_use;
                        pos = j;
                    }
                }
            }

            frame[pos] = page;
            page_faults++;
        }

        // Print frames
        printf("Frames: ");
        for (int j = 0; j < frames; j++)
            printf("%d ", frame[j]);
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", page_faults);

    return 0;
}
