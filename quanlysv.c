//#include <stdio.h>
//#include <string.h>
//
//struct Student {
//    int id;
//    char name[50];
//    int age;
//    float grade;
//};
//
//struct Student students[100];
//int studentCount = 0;
//
//void addStudent() {
//    printf("Nhap ID cua sinh vien: ");
//    scanf("%d", &students[studentCount].id);
//    printf("Nhap ten cua sinh vien: ");
//    scanf("%s", students[studentCount].name);
//    printf("Nhap tuoi cua sinh vien: ");
//    scanf("%d", &students[studentCount].age);
//    printf("Nhap diem so cua sinh vien: ");
//    scanf("%f", &students[studentCount].grade);
//    studentCount++;
//}
//
//void displayStudents() {
//    printf("Danh sách sinh viên:\n");
//    int i=0; 
//    for (; i < studentCount; i++) {
//        printf("ID: %d, Ten: %s, Tuoi: %d, Diem: %.2f\n", students[i].id, students[i].name, students[i].age, students[i].grade);
//    }
//}
//
//void updateStudent(int id) {
//	int i=0;
//    for (; i < studentCount; i++) {
//        if (students[i].id == id) {
//            printf("Nhap ten moi cua sinh vien: ");
//            scanf("%s", students[i].name);
//            printf("Nhap tuoi moi cua sinh vien: ");
//            scanf("%d", &students[i].age);
//            printf("Nhap diem so moi cua sinh vien: ");
//            scanf("%f", &students[i].grade);
//            printf("Thong tin sinh vien da duoc cap nhat!\n");
//            return;
//        }
//    }
//    printf("Khong tim thay sinh vien voi ID tuong ung.\n");
//}
//
//int main() {
//    int choice;
//    while (1) {
//        printf("Chon chuc nang:\n");
//        printf("1. Them sinh vien\n");
//        printf("2. Hien thi danh sach sinh vien\n");
//        printf("3. Cap nhat thong tin sinh vien\n");
//        printf("4. Thoat\n");
//        printf("Nhap su lua chon cua ban: ");
//        scanf("%d", &choice);
//
//        int id; // Di chuyen khai bao ra ngoai switch statement
//
//switch (choice) {
//    case 1:
//        addStudent();
//        break;
//    case 2:
//        displayStudents();
//        break;
//    case 3:
//        printf("Nhap ID cua sinh vien can cap nhat: ");
//        scanf("%d", &id);
//        updateStudent(id);
//        break;
//    case 4:
//        printf("Ket thuc chuong trinh.\n");
//        return 0;
//}
//        }
//    }




//bài 2 
#include <stdio.h>
#include <string.h>


typedef struct {
    int id;
    char name[50];
    float score;
} SinhVien;
void sortByname(SinhVien *list, int n) {
    int i, j;
    SinhVien temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(list[i].name, list[j].name) > 0) {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}
int searchByName(SinhVien *list, int n, char *name) {
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(list[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, i;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    SinhVien list[n];
    for (i = 0; i < n; i++) {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &list[i].id);
        printf("Ten: ");
        scanf("%s", list[i].name);
        printf("Diem: ");
        scanf("%f", &list[i].score);
    }
    sortByname(list, n);

    printf("\nDanh sach sinh vien sau khi sap xep theo ten:\n");
    for (i = 0; i < n; i++) {
        printf("ID: %d, Ten: %s, Diem: %.2f\n", list[i].id, list[i].name, list[i].score);
    }
    char searchName[50];
    printf("\nNhap ten sinh vien can tim: ");
    scanf("%s", searchName);

    int searchIndex = searchByName(list, n, searchName);
    if (searchIndex != -1) {
        printf("Sinh vien %s co trong danh sach. ID: %d, Diem: %.2f\n", searchName, list[searchIndex].id, list[searchIndex].score);
    } else {
        printf("Khong tim thay sinh vien %s trong danh sach.\n", searchName);
    }

    return 0;
}
