#include <stdio.h>

int main() {
    int frames, pages;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    int ref[pages], frame[frames];
    int front = 0, page_faults = 0;

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

        // If miss → replace using FIFO
        if (!hit) {
            frame[front] = page;
            front = (front + 1) % frames;
            page_faults++;
        }

        // Print current frame status
        printf("Frames: ");
        for (int j = 0; j < frames; j++)
            printf("%d ", frame[j]);
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", page_faults);

    return 0;
}
