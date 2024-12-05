#include <stdio.h>

#define MAX_SIZE 100

int isPerfectNumber(int n) {
    if (n <= 1) return 0;
    int sum = 1;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == n;
}

int reverseArray(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    return 0;
}

int rearrangeEvenOdd(int arr[], int n) {
    int temp[MAX_SIZE], index = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            temp[index++] = arr[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            temp[index++] = arr[i];
        }
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
    return 0;
}

int main() {
    int arr[MAX_SIZE], n, choice;

    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    if (n > MAX_SIZE || n <= 0) {
        printf("So phan tu khong hop le!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Nhap gia tri cho phan tu arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    do {
        printf("\nMenu\n");
        printf("1. In ra gia tri cac phan tu trong mang\n");
        printf("2. Dem so luong so hoan hao trong mang\n");
        printf("3. Tim gia tri lon thu 2 trong mang\n");
        printf("4. Them mot phan tu vao vi tri bat ky\n");
        printf("5. Xoa phan tu tai mot vi tri bat ky\n");
        printf("6. Sap xep mang theo thu tu tang dan\n");
        printf("7. Sap xep so chan dung truoc, so le dung sau\n");
        printf("8. Dao nguoc thu tu cac phan tu trong mang\n");
        printf("9. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Cac phan tu trong mang:\n");
                for (int i = 0; i < n; i++) {
                    printf("arr[%d] = %d\n", i, arr[i]);
                }
                break;

            case 2: {
                int count = 0;
                for (int i = 0; i < n; i++) {
                    if (isPerfectNumber(arr[i])) {
                        count++;
                    }
                }
                printf("So luong so hoan hao trong mang: %d\n", count);
                break;
            }

            case 3: {
                if (n < 2) {
                    printf("Mang khong du phan tu de tim gia tri lon thu 2.\n");
                } else {
                    int max = arr[0], secondMax = -1;
                    for (int i = 1; i < n; i++) {
                        if (arr[i] > max) {
                            secondMax = max;
                            max = arr[i];
                        } else if (arr[i] > secondMax && arr[i] != max) {
                            secondMax = arr[i];
                        }
                    }
                    if (secondMax == -1) {
                        printf("Khong ton tai gia tri lon thu 2.\n");
                    } else {
                        printf("Gia tri lon thu 2 trong mang: %d\n", secondMax);
                    }
                }
                break;
            }

            case 4: {
                if (n >= MAX_SIZE) {
                    printf("Khong the them phan tu, mang da day.\n");
                    break;
                }
                int pos, value;
                printf("Nhap gia tri phan tu moi: ");
                scanf("%d", &value);
                printf("Nhap vi tri them vao (0-%d): ", n);
                scanf("%d", &pos);

                if (pos < 0 || pos > n) {
                    printf("Vi tri khong hop le!\n");
                } else {
                    for (int i = n; i > pos; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[pos] = value;
                    n++;
                    printf("Them phan tu thanh cong.\n");
                }
                break;
            }

            case 5: {
                int pos;
                printf("Nhap vi tri muon xoa (0-%d): ", n - 1);
                scanf("%d", &pos);

                if (pos < 0 || pos >= n) {
                    printf("Vi tri khong hop le!\n");
                } else {
                    for (int i = pos; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                    printf("Xoa phan tu thanh cong.\n");
                }
                break;
            }

            case 6: {
                for (int i = 1; i < n; i++) {
                    int key = arr[i];
                    int j = i - 1;
                    while (j >= 0 && arr[j] > key) {
                        arr[j + 1] = arr[j];
                        j--;
                    }
                    arr[j + 1] = key;
                }
                printf("Mang da duoc sap xep tang dan.\n");
                break;
            }

            case 7:
                rearrangeEvenOdd(arr, n);
                printf("Mang da duoc sap xep: So chan dung truoc, so le dung sau.\n");
                break;

            case 8:
                reverseArray(arr, n);
                printf("Mang da duoc dao nguoc.\n");
                break;

            case 9:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 9);

    return 0;
}

