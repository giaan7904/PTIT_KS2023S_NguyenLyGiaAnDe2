#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_TODO 100

typedef struct {
    int id;
    char startDate[50];
    char endDate[50];
    char content[100];
    bool status;
} Todo;

Todo todoList[MAX_TODO];
int numTodos = 2;

void printTodoList() {
    printf("Danh sach Todo:\n");
    for (int i = 0; i < numTodos; i++) {
        printf("ID: %d\n", todoList[i].id);
        printf("Start Date: %s\n", todoList[i].startDate);
        printf("End Date: %s\n", todoList[i].endDate);
        printf("Content: %s\n", todoList[i].content);
        printf("Status: %s\n", todoList[i].status ? "Hoan thanh" : "Chua hoan thanh");
        printf("--------------------\n");
    }
}

void addTodo() {
    if (numTodos >= MAX_TODO) {
        printf("Danh sach Todo da day.\n");
        return;
    }

    Todo newTodo;
    printf("Nhap Start Date: ");
    scanf("%s", newTodo.startDate);
    printf("Nhap End Date: ");
    scanf("%s", newTodo.endDate);
    printf("Nhap Content: ");
    scanf(" %[^\n]s", newTodo.content);
    newTodo.status = false;

    newTodo.id = numTodos + 1;
    todoList[numTodos] = newTodo;
    numTodos++;

    printf("Da them Todo moi.\n");
}

void updateTodo() {
    char content[100];
    printf("Nhap Content cua Todo muon chinh sua: ");
    scanf(" %[^\n]s", content);

    bool found = false;
    for (int i = 0; i < numTodos; i++) {
        if (strcmp(todoList[i].content, content) == 0) {
            printf("Nhap Start Date moi: ");
            scanf("%s", todoList[i].startDate);
            printf("Nhap End Date moi: ");
            scanf("%s", todoList[i].endDate);
            printf("Nhap Content moi: ");
            scanf(" %[^\n]s", todoList[i].content);
            found = true;
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay Todo.\n");
    } else {
        printf("Da cap nhat Todo.\n");
    }
}

void deleteTodo() {
    char content[100];
    printf("Nhap Content cua Todo muon xoa: ");
    scanf(" %[^\n]s", content);

    bool found = false;
    for (int i = 0; i < numTodos; i++) {
        if (strcmp(todoList[i].content, content) == 0) {
            for (int j = i; j < numTodos - 1; j++) {
                todoList[j] = todoList[j + 1];
            }
            numTodos--;
            found = true;
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay Todo.\n");
    } else {
        printf("Da xoa Todo.\n");
    }
}

void selectionSort() {
    for (int i = 0; i < numTodos - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < numTodos; j++) {
            if (strcmp(todoList[j].content, todoList[minIndex].content) < 0) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            Todo temp = todoList[i];
            todoList[i] = todoList[minIndex];
            todoList[minIndex] = temp;
        }
    }

    printf("Da sap xep danh sach Todo tang dan theo Content.\n");
}

int binarySearch(char content[100]) {
    int left = 0;
    int right = numTodos - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (strcmp(todoList[mid].content, content) == 0) {
            return mid;
        } else if (strcmp(todoList[mid].content, content) < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

void searchTodo() {
    char content[100];
    printf("Nhap Content cua Todo muon tim kiem: ");
    scanf(" %[^\n]s", content);

    int index = binarySearch(content);
    if (index != -1) {
        printf("Tim thay Todo:\n");
        printf("ID: %d\n", todoList[index].id);
        printf("Start Date: %s\n", todoList[index].startDate);
        printf("End Date: %s\n", todoList[index].endDate);
        printf("Content: %s\n", todoList[index].content);
        printf("Status: %s\n", todoList[index].status ? "Hoan thanh" : "Chua hoan thanh");
    } else {
        printf("Khong tim thay Todo.\n");
    }
}

void searchByStatus() {
    bool status;
    printf("Nhap trang thai Todo (1 - Hoan thanh, 0 - Chua hoan thanh): ");
    scanf("%d", &status);

    printf("Danh sach Todo theo trang thai:\n");
    for (int i = 0; i < numTodos; i++) {
        if (todoList[i].status == status) {
            printf("ID: %d\n", todoList[i].id);
            printf("Start Date: %s\n", todoList[i].startDate);
            printf("End Date: %s\n", todoList[i].endDate);
            printf("Content: %s\n", todoList[i].content);
            printf("Status: %s\n", todoList[i].status ? "Hoan thanh" : "Chua hoan thanh");
            printf("--------------------\n");
        }
    }
}

int main() {
    todoList[0].id = 1;
    strcpy(todoList[0].startDate, "01/01/2022");
    strcpy(todoList[0].endDate, "05/01/2022");
    strcpy(todoList[0].content, "Lam bai tap C");
    todoList[0].status = false;

    todoList[1].id = 2;
    strcpy(todoList[1].startDate, "02/01/2022");
    strcpy(todoList[1].endDate, "07/01/2022");
    strcpy(todoList[1].content, "Nop bai tap C");
    todoList[1].status = true;

    int choice;
    do {
        printf("************************MENU**************************\n");
        printf("1. In toan bo danh sach Todo\n");
        printf("2. Them moi Todo\n");
        printf("3. Cap nhat thong tin Todo\n");
        printf("4. Xoa mot Todo\n");
        printf("5. Sap xep danh sach Todo\n");
        printf("6. Tim kiem Todo\n");
        printf("7. Tim kiem Todo theo trang thai\n");
        printf("0. Thoat\n");
        printf("******************************************************\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printTodoList();
                break;
            case 2:
                addTodo();
                break;
            case 3:
                updateTodo();
                break;
            case 4:
                deleteTodo();
                break;
            case 5:
                selectionSort();
                break;
            case 6:
                searchTodo();
                break;
            case 7:
                searchByStatus();
                break;
            case 0:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
