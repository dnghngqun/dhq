/*
Student { id, name, email, mark }
1. Thêm mới một đối tượng Student
2. Hiển thị toàn bộ danh sách
3. Tìm một sinh viên theo mã id
4. Sắp xếp sinh viên theo điểm
5. Sửa thông tin sinh viên
6. Ghi toàn bộ thông tin xuống file (nâng cao, tùy chọn không bắt buộc làm)
7. Thoát chương trình 
*/

#include<stdio.h>
#include<string.h>

//function prototype
void menu();
void input(int );
void print(int );
long find(long );
void sort();
void edit();
void output_file();

//global variable
int count = 0;
int n = 0;
int i = 0;
int j = 0;
//create struct student
struct student
{	
	long id;
	char name[50];
	char email[100];
	float mark;
};


struct student sv[];

//create menu
void menu()
{
	printf("1. Add a new Student object\n");
	printf("2. Show all list\n");
	printf("3. Find a student with id\n");
	printf("4. Sort students by grades\n");
	printf("5. Edit student information\n");
	printf("6. Write all information to the file\n");
	printf("7. Exit\n");
	printf("\nEnter option: ");
	scanf("%d", &n);
}

//Enter student information
void input(int index)
{
	printf("Enter id: ");
	scanf("%ld", &sv[index].id);
	fflush(stdin);
	
	printf("Enter name: ");
	gets(sv[index].name);

	printf("Enter email: ");
	gets(sv[index].email);
	
	printf("Enter mark: ");
	scanf("%f", &sv[index].mark);
	fflush(stdin);
}
//print out student information
void print(int index)
{
	printf("%ld %s %s %.2f\n", sv[index].id, sv[index].name, sv[index].email, sv[index].mark);
}
//Student information search
long find(long c)
{
	for(i = 0; i < count; i++)
	{
		if(c == sv[i].id)
		{
			return i;
		}
	}
	return -1;
}

//sort
void sort()
{
	if(count == 0)
	{
		printf("No students to sort.\n");
	}
	else
	{
		float temp = 0;
		char temp1[100];
		long temp2 = 0;
		for(i = 0; i < count; i++)
		{
			for(j = i + 1; j < count; j++)
			{
				if(sv[j].mark > sv[i].mark) //sắp xếp từ cao > thấp
				{		
					//sort mark 
					temp = sv[j].mark;
					sv[j].mark = sv[i].mark;
					sv[i].mark = temp;
				
					//sort id
					temp2 = sv[j].id;
					sv[j].id = sv[i].id;
					sv[i].id = temp2;
				
					//sort email
					strcpy(temp1, sv[j].email);
					strcpy(sv[j].email, sv[i].email);
					strcpy(sv[i].email, temp1);
				
					//sort name
					strcpy(temp1, sv[j].name);
					strcpy(sv[j].name, sv[i].name);
					strcpy(sv[i].name, temp1);
				}
			}
		}
		printf("Students sorted by mark.\n");
	}
}

//edit studient information
void edit()
{
	long c = 0;
	printf("Enter id to edit infomation: ");
	scanf("%ld", &c);
	fflush(stdin);
	
	int a = find(c);
	if(a == -1)
	{
		printf("Student information could not be found\n");
	}
	else
	{
		printf("\nStudent's current information is:\n");
		print(i);
					
		printf("\nRe-enter modified information:\n");
		printf("\tEnter name: ");
		gets(sv[a].name);
		printf("\tEnter email: ");
		gets(sv[a].email);	
		printf("\tEnter mark: ");
		scanf("%f", &sv[a].mark);
		fflush(stdin);	
	}
}

//Write all information to the file
void output_file()
{
	FILE *file = fopen("information_Student.txt", "w");
	if(file == NULL)
	{
		printf("Failed to open file.\n");
		return;
	}
	for(i = 0; i < count;i++){
		fprintf(file, "%ld %s %s %.2f\n", sv[i].id, sv[i].name, sv[i].email, sv[i].mark);
	}
	fclose(file);
	printf("Write all information to the file success!\n");
}

//main
int main()
{
	char choice;
	long c = 0;
	do
	{
		menu();
		switch (n)
		{
			case 1:
				input(count);
				count++;
				break;
			case 2:
				for(i = 0; i < count; i++){
					print(i);
				}
				break;
			case 3:
				printf("Enter id to search: ");
				scanf("%ld", &c);
				fflush(stdin);
				int d = find(c);
				if(d == -1)
				{
					printf("Student information could not be found\n");
				}
				else
					printf("%lld %s %s %.2f\n", sv[d].id, sv[d].name, sv[d].email, sv[d].mark);
				break;
			case 4:
				sort();
				break;
			case 5:
				edit();
				break;
			case 6:
				output_file();
				break;
			case 7:
				printf("Exit program...");
				return 0;
				break;
			default:
				printf("Invalid option!\n");
		}
		//The question appears when the program is finished
		printf("\nDO U WANT TO SELECT ANOTHER OPTION?(y/n): ");
		choice = getchar();
		printf("\n");
		fflush(stdin);
		while(!(choice == 'y' || choice =='n' || choice == 'Y' || choice == 'N'))
		{
			printf("PLEASE RE-ENTER OPTION(y/n): ");
			choice = getchar();
			printf("\n");
			fflush(stdin);
		}
		if(choice == 'N' || choice == 'n')		return 0;
		//
	}while(1);
	return 0;
}