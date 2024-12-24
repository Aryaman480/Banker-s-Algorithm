#include <stdio.h> 
#include <stdbool.h> 
#define P 5 
#define R 4 
void calculateNeed(int need[P][R], int max[P][R], int allot[P][R]) 
{ 
for (int i = 0; i < P; i++) 
for (int j = 0; j < R; j++) 
need[i][j] = max[i][j] - allot[i][j]; 
} 
bool isSafe(int processes[], int avail[], int max[][R], int allot[][R]) 
{ 
int need[P][R]; 
calculateNeed(need, max, allot); 
bool finished[P] = {false}; 
int safeSequence[P]; 
int work[R]; 
for (int i = 0; i < R; i++) 
work[i] = avail[i]; 
int count = 0; 
while (count < P) 
{ 
bool found = false; 
for (int i = 0; i < P; i++) 
{ 
if (!finished[i]) 
{ 
bool canAllocate = true; 
for (int j = 0; j < R; j++) 
if (need[i][j] > work[j]) 
{ 
canAllocate = false; 
break; 
} 
if (canAllocate) 
{ 
for (int j = 0; j < R; j++) 
work[j] += allot[i][j]; 
safeSequence[count++] = processes[i]; 
finished[i] = true; 
found = true; 
} 
} 
} 
if (!found) 
{ 
printf("System is not in a safe state.\n"); 
return false; 
} 
} 
printf("System is in a safe state.\nSafe sequence is: "); 
for (int i = 0; i < P; i++) 
printf("%d ", safeSequence[i]); 
printf("\n"); 
return true; 
} 
int main() 
{ 
int processes[] = {0, 1, 2, 3, 4}; 
int avail[] = {6, 7, 12, 12}; 
int max[P][R] = {{0, 0, 1, 2},{2, 7, 5, 0},{6, 6, 5, 6},{4, 3, 5, 6}, {0, 6, 5, 2}}; 
int allot[P][R] = {{0, 0, 1, 2},{2, 0, 0, 0},{0, 0, 3, 4},{2, 3, 5, 4},{0, 3, 3, 2}}; 
isSafe(processes, avail, max, allot); 
return 0; 
}