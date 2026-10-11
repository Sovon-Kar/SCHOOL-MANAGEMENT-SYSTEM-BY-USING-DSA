#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student
{
	int roll;
	char name[60];
	int Class;
	char section;
	struct student *next;
}st;
typedef struct teacher
{
	int id;
	char name[60];
	char classes_taught[20];
	struct teacher *next;
}tr;
typedef struct marks
{
	int roll;
	char subject[30];
	int marks;
	int Class;
	struct marks *next;
}m;
int ch;
st *head[13]={NULL};
tr *head_teacher=NULL;
m *head_marks=NULL;
void insert_student(void);
void student_management(void);
void display_student(void);
void delete_student(void);
void search_student(void);
void update_roll(void);
void update_name(void);
void update_class(void);
void update_section(void);
void sort_students(void);
void teacher_management(void);
void insert_teacher(void);
void display_teacher(void);
void delete_teacher(void);
void search_teacher(void);
void update_teacher(void);
void sort_teachers(void);
void update_student_details(void);
void update_id(void);
void update_tname(void);
void update_classes_taught(void);
void sort_teachers(void);
void marks_management(void);
void insert_marks(void);
void display_marks(void);
void search_marks(void);
void update_marks(void);
void delete_marks(void);
void load_data(void);
void save_data(void);
void load_students(void);
void load_teachers(void);
void load_marks(void);
void save_students(void);
void save_teachers(void);
void save_marks(void);
int main()
{
	load_data();
	
	do
	{
	printf("\n =========SCHOOL MANAGEMENT SYSYTEM=========");
	printf("\n 1. Student Management");
	printf("\n 2. Teachers Management");
	printf("\n 3. Marks Management");
	printf("\n 4. Exit");
		printf("\nEnter your choice:");
	    scanf("%d",&ch);
	    switch(ch)
	    {
	    	case 1:
	    		student_management();
	    		break;
	        case 2:
	        	teacher_management();
	        	break;
	        case 3:
	        	marks_management();
	        	break;
	        case 4:
	        	break;
	        default:
	        	printf("\nInvalid Input");
	        	break;
		}
		
	}while(ch!=4);
	save_data();
	printf("\nRecords saved successfully.");
	return 0;
}
void student_management(void)
{
    int choice;

    do
    {
        printf("\n\n========== STUDENT MANAGEMENT ==========");
        printf("\n1. Insert Student");
        printf("\n2. Display Students");
        printf("\n3. Delete Student");
        printf("\n4. Search Student");
        printf("\n5. Update Student");
        printf("\n6. Sort Students");
        printf("\n7. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                insert_student();
                break;

            case 2:
                display_student();
                break;

            case 3:
                delete_student();
                break;

            case 4:
                search_student();
                break;

            case 5:
                update_student_details();
                break;

            case 6:
                sort_students();
                break;

            case 7:
                break;

            default:
                printf("\nInvalid Input");
        }

    }while(choice != 7);
}
void insert_student(void)
{
    char v;
   	int cls;
   	printf("\nEnter the class in which you want to insert the new student:");
   	scanf("%d",&cls);
   	if(cls<1 || cls>12)    	
	{
    	printf("\nInvalid class");
    	return;
	}
	st *new1=(st *)malloc(sizeof(st));
	printf("\nEnter the roll number of the student:");
	scanf("%d",&new1->roll);
	getchar();
	printf("\nEnter the student name:");
	fgets(new1->name,sizeof(new1->name),stdin);
	new1->name[strcspn(new1->name,"\n")] = '\0';
	new1->Class=cls;
	printf("\nEnter the section of the student:");
	scanf(" %c",&new1->section);
	new1->next=NULL;
	if(head[cls]==NULL)
	head[cls]=new1;
	else
	{
		st *p=head[cls];
		while(p->next!=NULL)
		p=p->next;
		p->next=new1;
	}
	printf("\nStudent Record Inserted Successfully");
	save_students();
	printf("\nDo you want to insert any other student?(y/n)");
	scanf(" %c",&v);
	if(v=='y'||v=='Y')
	insert_student();
}
void display_student(void)
{
    int cls;

    printf("\nEnter the class whose students you want to display: ");
    scanf("%d",&cls);

    if(cls < 1 || cls > 12)
    {
        printf("\nInvalid class");
        return;
    }

    st *p = head[cls];

    if(p == NULL)
    {
        printf("\nNo students found in this class");
        return;
    }

    printf("\n=========================================================");
    printf("\n                    STUDENT DETAILS");
    printf("\n=========================================================");
    
    printf("\n%-10s %-25s %-10s %-10s",
           "Roll No", "Name", "Class", "Section");

    printf("\n---------------------------------------------------------");

    while(p != NULL)
    {
        printf("\n%-10d %-25s %-10d %-10c",
               p->roll,
               p->name,
               p->Class,
               p->section);

        p = p->next;
    }

    printf("\n=========================================================");
}
void delete_student(void)
{
    int cls;
    int r,f=0;
    char v;

    printf("\nEnter the class whose students you want to delete: ");
    scanf("%d",&cls);

    if(cls < 1 || cls > 12)
    {
        printf("\nInvalid class");
        return;
    }
    printf("\nEnter the roll number of the student you want to delete:");
    scanf("%d",&r);

    if(head[cls]==NULL)
    {
        printf("\nNo record of students in this particular class.");
        return;
    }
    st *p=head[cls];
    if(p->roll==r && p->next==NULL)
    {
        free(head[cls]);
        head[cls]=NULL;
        f=1;

        printf("\nList is now empty.");
        printf("\nDeletion is successful");

        printf("\nDo you want to delete any other student?(y/n): ");
        scanf(" %c",&v);

        if(v=='y'||v=='Y')
            delete_student();

        return;
    }
    st *p1=p->next;
    if(p->roll==r)
    {
        st *loc=p;
        head[cls]=p->next;
        free(loc);
        f=1;

        printf("\nDeletion is successful");

        printf("\nDo you want to delete any other student?(y/n): ");
        scanf(" %c",&v);

        if(v=='y'||v=='Y')
            delete_student();

        return;
    }
    while(p1!=NULL)
    {
        if(p1->roll==r)
        {
            st *loc=p1;
            p->next=p1->next;
            free(loc);
            f=1;
            break;
        }

        p=p->next;
        p1=p1->next;
    }

    if(f==1)
    {
        printf("\nDeletion is successful");
        save_students();
        printf("\nDo you want to delete any other student?(y/n): ");
        scanf(" %c",&v);

        if(v=='y'||v=='Y')
            delete_student();
    }
    else
    {
        printf("\nStudent NOT found.");
    }
}
void search_student(void)
{
    int cls;
    int r,f=0;
    char v;

    printf("\nEnter the class whose students you want to search: ");
    scanf("%d",&cls);

    if(cls < 1 || cls > 12)
    {
        printf("\nInvalid class");
        return;
    }
    printf("\nEnter the roll number of the student you want to search:");
    scanf("%d",&r);
    if(head[cls]==NULL)
    {
    	printf("\nStudent details of this class is empty.");
    	return;
	}
    st *p=head[cls];
    printf("\n=========================================================");
    printf("\n                    STUDENT DETAILS");
    printf("\n=========================================================");
    
    printf("\n%-10s %-25s %-10s %-10s",
           "Roll No", "Name", "Class", "Section");

    printf("\n---------------------------------------------------------");

    while(p!=NULL)
    {
    	if(p->roll==r)
    	{
    		printf("\n%-10d %-25s %-10d %-10c",
               p->roll,
               p->name,
               p->Class,
               p->section);
               f=1;
               break;
		}
		p=p->next;
    }
    if(f==1)
    printf("\nSearch successful");
    else
    printf("\nStudent does NOT exist.");
    printf("\nDo you want to search any other student?(y/n): ");
    scanf(" %c",&v);
    if(v=='y'||v=='Y')
    search_student();
}
void update_student_details(void)
{
	char v;
    printf("\n1.Roll");
    printf("\n2.Name");
    printf("\n3.Class");
    printf("\n4.Section");
    printf("\n5.Exit");
    do
    {
    	printf("\nEnter your choice:");
    	scanf("%d",&ch);
    	switch(ch)
    	{
    		case 1:
    			update_roll();
    			break;
    		case 2:
    			update_name();
    			break;
    		case 3:
    			update_class();
    			break;
    		case 4:
    			update_section();
    			break;
    		case 5:
    			break;	
		}
	}while(ch!=5);
	save_students();
	printf("\nDo you want to  update details of any other student?(y/n): ");
    scanf(" %c",&v);
    if(v=='y'||v=='Y')
    update_student_details();
}
void update_roll(void)
{
	int cls;
    int r,t,nr,f=0;
    char v;

    printf("\nEnter the class of the student whose roll number you want to update: ");
    scanf("%d",&cls);

    if(cls < 1 || cls > 12)
    {
        printf("\nInvalid class");
        return;
    }
    if(head[cls]==NULL)
    {
    	printf("\nStudent details of this class is empty.");
    	return;
	}
    printf("\nEnter the roll number of the student you want to update:");
    scanf("%d",&r);
    st *p=head[cls];
    while(p!=NULL)
    {
    	if(p->roll==r)
    	{
    		printf("\nEnter the new roll number of the student:");
    		scanf("%d",&nr);
    		p->roll=nr;
    		f=1;
    		break;
		}
		p=p->next;
	}
	if(f==1)
	printf("\nUpdation is successful.");
	printf("\nDo you want to  update roll number of any other student?(y/n): ");
    scanf(" %c",&v);
    if(v=='y'||v=='Y')
    update_roll();
}
void update_name(void)
{
    int cls;
    int r, f = 0;
    char v, nnm[60];

    printf("\nEnter the class of the student whose name you want to update: ");
    scanf("%d", &cls);

    if(cls < 1 || cls > 12)
    {
        printf("\nInvalid class");
        return;
    }

    if(head[cls] == NULL)
    {
        printf("\nStudent details of this class is empty.");
        return;
    }

    printf("\nEnter the roll number of the student whose name you want to update: ");
    scanf("%d", &r);

    st *p = head[cls];

    while(p != NULL)
    {
        if(p->roll == r)
        {
            getchar();

            printf("\nEnter the updated name of the student: ");
            fgets(nnm, sizeof(nnm), stdin);

            nnm[strcspn(nnm, "\n")] = '\0';

            strcpy(p->name, nnm);

            f = 1;
            break;
        }

        p = p->next;
    }

    if(f == 0)
    {
        printf("\nStudent with the given roll number does NOT exist.");
        return;
    }

    printf("\nName updated successfully.");

    printf("\nDo you want to update name of any other student?(y/n): ");
    scanf(" %c", &v);

    if(v == 'y' || v == 'Y')
    update_name();
}

void update_class(void)
{
    int cls;
    int r, newcls, f = 0;
    char v;
    printf("\nEnter the class of the student whose class you want to update: ");
    scanf("%d", &cls);
    if(cls < 1 || cls > 12)
    {
        printf("\nInvalid class");
        return;
    }
    if(head[cls] == NULL)
    {
        printf("\nStudent details of this class is empty.");
        return;
    }
    printf("\nEnter the roll number of the student whose class you want to update: ");
    scanf("%d", &r);
    st *p = head[cls];
    st *prev = NULL;
    while(p != NULL)
    {
        if(p->roll == r)
        {
            f = 1;
            break;
        }

        prev = p;
        p = p->next;
    }
    if(f == 0)
    {
        printf("\nStudent with the given roll number does NOT exist.");
        return;
    }
    printf("\nEnter the new class: ");
    scanf("%d", &newcls);
    if(newcls==cls)
    {
    	printf("\nStudent is already in the desired class.");
    	return;
	}

    if(newcls < 1 || newcls > 12)
    {
        printf("\nInvalid class");
        return;
    }
    if(prev == NULL)
    {
        head[cls] = p->next;
    }
    else
    {
        prev->next = p->next;
    }
    p->Class = newcls;
    p->next = head[newcls];
    head[newcls] = p;
    printf("\nClass updated successfully.");
    printf("\nDo you want to update class of any other student?(y/n): ");
    scanf(" %c", &v);
    if(v == 'y' || v == 'Y')
    update_class();
}
void update_section(void)
{
	int cls;
    int r,f=0;
    char v,ns;

    printf("\nEnter the class of the student whose section you want to update: ");
    scanf("%d",&cls);

    if(cls < 1 || cls > 12)
    {
        printf("\nInvalid class");
        return;
    }
    if(head[cls]==NULL)
    {
    	printf("\nStudent details of this class is empty.");
    	return;
	}
    printf("\nEnter the roll number of the student whose section you want to update:");
    scanf("%d",&r);
    st *p=head[cls];
    while(p!=NULL)
    {
    	if(p->roll==r)
    	{
    		printf("\nEnter the new section:");
    		scanf(" %c",&ns);
    		p->section=ns;
    		f=1;
    		break;
		}
		p=p->next;
	}
	if(f == 0)
    {
        printf("\nStudent with the given roll number does NOT exist.");
        return;
    }

    printf("\nSection updated successfully.");

    printf("\nDo you want to update section of any other student?(y/n): ");
    scanf(" %c", &v);

    if(v == 'y' || v == 'Y')
    update_section();
}

void sort_students(void)
{
    st *p, *p1;
    int i, s;
    char sec, nm[60];

    for(i = 1; i <= 12; i++)
    {
        for(p = head[i]; p != NULL; p = p->next)
        {
            for(p1 = p->next; p1 != NULL; p1 = p1->next)
            {
                if(p->roll > p1->roll)
                {
                    s = p->roll;
                    p->roll = p1->roll;
                    p1->roll = s;

                    strcpy(nm, p->name);
                    strcpy(p->name, p1->name);
                    strcpy(p1->name, nm);

                    s = p->Class;
                    p->Class = p1->Class;
                    p1->Class = s;

                    sec = p->section;
                    p->section = p1->section;
                    p1->section = sec;
                }
            }
        }
    }
    save_students();
    printf("\nStudents sorted successfully.");
}
void teacher_management(void)
{
    int choice;

    do
    {
        printf("\n\n========== TEACHER MANAGEMENT ==========");
        printf("\n1. Insert Teacher");
        printf("\n2. Display Teachers");
        printf("\n3. Delete Teacher");
        printf("\n4. Search Teacher");
        printf("\n5. Update Teacher");
        printf("\n6. Sort Teachers");
        printf("\n7. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                insert_teacher();
                break;

            case 2:
                display_teacher();
                break;

            case 3:
                delete_teacher();
                break;

            case 4:
                search_teacher();
                break;

            case 5:
                update_teacher();
                break;

            case 6:
                sort_teachers();
                break;

            case 7:
                break;

            default:
                printf("\nInvalid Input");
        }

    }while(choice != 7);
}
void insert_teacher(void)
{
    tr *new1, *p;
    char v;
    new1 = (tr*)malloc(sizeof(tr));
    if(new1 == NULL)
    {
        printf("\nMemory allocation failed.");
        return;
    }
    printf("\nEnter teacher ID: ");
    scanf("%d",&new1->id);
    getchar();
    printf("\nEnter teacher name: ");
    fgets(new1->name,sizeof(new1->name),stdin);
    new1->name[strcspn(new1->name,"\n")] = '\0';
    printf("\nEnter classes taught: ");
    fgets(new1->classes_taught,sizeof(new1->classes_taught),stdin);
    new1->classes_taught[strcspn(new1->classes_taught,"\n")] = '\0';
    new1->next = NULL;
    if(head_teacher == NULL)
    {
        head_teacher = new1;
    }
    else
    {
        p = head_teacher;
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = new1;
    }
    printf("\nTeacher inserted successfully.");
    save_teachers();
    printf("\nDo you want to insert any other teacher?(y/n)");
	scanf(" %c",&v);
	if(v=='y'||v=='Y')
	insert_teacher();
}
void display_teacher(void)
{
    tr *p;

    if(head_teacher == NULL)
    {
        printf("\nNo teacher records found.");
        return;
    }

    p = head_teacher;

    printf("\n=========================================================");
    printf("\n                    TEACHER DETAILS");
    printf("\n=========================================================");

    printf("\n%-10s %-25s %-20s",
           "ID", "Name", "Classes Taught");

    printf("\n---------------------------------------------------------");

    while(p != NULL)
    {
        printf("\n%-10d %-25s %-20s",
               p->id,
               p->name,
               p->classes_taught);

        p = p->next;
    }

    printf("\n=========================================================");
}
void delete_teacher(void)
{
    int i,f=0;
    tr *p,*p1;
    char v;

    if(head_teacher == NULL)
    {
        printf("\nNo teacher records found.");
        return;
    }

    printf("\nEnter the id of the teacher you want to delete:");
    scanf("%d",&i);

    p = head_teacher;

    if(p->id == i)
    {
        head_teacher = p->next;
        free(p);
        f = 1;
    }
    else
    {
        p1 = p->next;

        while(p1 != NULL)
        {
            if(p1->id == i)
            {
                p->next = p1->next;
                free(p1);
                f = 1;
                break;
            }

            p = p1;
            p1 = p1->next;
        }
    }

    if(f == 1)
        printf("\nDeletion is successful");
    else
        printf("\nTeacher with given ID is NOT found");
    save_teachers();
    printf("\nDo you want to delete any other teacher?(y/n)");
    scanf(" %c",&v);

    if(v=='y'||v=='Y')
        delete_teacher();
}
void search_teacher(void)
{
	int i,f=0;
    tr *p;
    char v;

    if(head_teacher == NULL)
    {
        printf("\nNo teacher records found.");
        return;
    }

    printf("\nEnter the id of the teacher you want to search:");
    scanf("%d",&i);

    p = head_teacher;
    while(p!=NULL)
    {
    	if(p->id==i)
    	{
    		f=1;
    		break;
		}
		p=p->next;
	}
	if(f==1)
{
    printf("\n=========================================================");
    printf("\n                    TEACHER DETAILS");
    printf("\n=========================================================");
    printf("\n%-10s %-25s %-20s",
           "ID", "Name", "Classes Taught");
    printf("\n---------------------------------------------------------");

    printf("\n%-10d %-25s %-20s",
           p->id,
           p->name,
           p->classes_taught);

    printf("\nSearch is successful.");
}
	else
	printf("\nSearch is Unsuccessful");
	printf("\nDo you want to search any other teacher?(y/n)");
    scanf(" %c",&v);
    if(v=='y'||v=='Y')
    search_teacher();
}
void update_teacher(void)
{
	char v;
    printf("\n1.ID");
    printf("\n2.Name");
    printf("\n3.Classes taught");
    printf("\n4.Exit");
    do
    {
    	printf("\nEnter your choice:");
    	scanf("%d",&ch);
    	switch(ch)
    	{
    		case 1:
    			update_id();
    			break;
    		case 2:
    			update_tname();
    			break;
    		case 3:
    			update_classes_taught();
    			break;
    		case 4:
    			break;	
		}
	}while(ch!=4);
	save_teachers();
	printf("\nDo you want to  update details of any other teacher?(y/n): ");
    scanf(" %c",&v);
    if(v=='y'||v=='Y')
    update_teacher();
}
void update_id(void)
{
	int f=0,i,ni;
    char v;

    printf("\nEnter the ID of the teacher whose ID you want to update: ");
    scanf("%d",&i);

    if(head_teacher==NULL)
    {
    	printf("\nTeacher records are empty.");
    	return;
	}
    tr *p=head_teacher;
    while(p!=NULL)
    {
    	if(p->id==i)
    	{
    		printf("\nEnter the new ID of the teacher:");
    		scanf("%d",&ni);
    		p->id=ni;
    		f=1;
    		break;
		}
		p=p->next;
	}
	if(f==1)
	printf("\nUpdation of ID is successful.");
	else
	printf("\nTeacher with entered ID is not found.");
	printf("\nDo you want to  update ID of any other teacher?(y/n): ");
    scanf(" %c",&v);
    if(v=='y'||v=='Y')
    update_id();
}
void update_tname()
{
	int f=0,i;
    char v,nnm[60];

    printf("\nEnter the ID of the teacher whose name you want to update: ");
    scanf("%d",&i);

    if(head_teacher==NULL)
    {
    	printf("\nTeacher records are empty.");
    	return;
	}
    tr *p=head_teacher;
    while(p!=NULL)
    {
    	if(p->id==i)
    	{
    	    getchar();
            printf("\nEnter the updated name of the teacher: ");
            fgets(nnm, sizeof(nnm), stdin);
            nnm[strcspn(nnm, "\n")] = '\0';
            strcpy(p->name,nnm);
            f = 1;
            break;
		}
		p=p->next;
	}
	if(f==1)
	printf("\nUpdation of name is successful.");
	else
	printf("\nTeacher with entered ID is not found.");
	printf("\nDo you want to  update  name of any other teacher?(y/n): ");
    scanf(" %c",&v);
    if(v=='y'||v=='Y')
    update_tname();
}
void update_classes_taught(void)
{
	int f=0,i;
    char v,ncl[20];

    printf("\nEnter the ID of the teacher whose classes you want to update: ");
    scanf("%d",&i);

    if(head_teacher==NULL)
    {
    	printf("\nTeacher records are empty.");
    	return;
	}
    tr *p=head_teacher;
    while(p!=NULL)
    {
    	if(p->id==i)
    	{
    	    getchar();
            printf("\nEnter the updated classes being taught by the teacher: ");
            fgets(ncl, sizeof(ncl), stdin);
            ncl[strcspn(ncl, "\n")] = '\0';
            strcpy(p->classes_taught,ncl);
            f = 1;
            break;
		}
		p=p->next;
	}
	if(f==1)
	printf("\nUpdation of classes being taught by the teacher is successful.");
	else
	printf("\nTeacher with entered ID is not found.");
	printf("\nDo you want to update classes taught by any other teacher?(y/n): ");
    scanf(" %c",&v);
    if(v=='y'||v=='Y')
    update_classes_taught();
}
	
void sort_teachers(void)
{
    tr *p, *p1;
    tr temp;
    if(head_teacher==NULL)
    {
    	printf("\nTeacher records are empty.");
    	return;
	}
    for(p = head_teacher; p != NULL; p = p->next)
    {
        for(p1 = p->next; p1 != NULL; p1 = p1->next)
        {
            if(p->id > p1->id)
            {
                temp.id = p->id;
                p->id = p1->id;
                p1->id = temp.id;

                strcpy(temp.name, p->name);
                strcpy(p->name, p1->name);
                strcpy(p1->name, temp.name);

                strcpy(temp.classes_taught, p->classes_taught);
                strcpy(p->classes_taught, p1->classes_taught);
                strcpy(p1->classes_taught, temp.classes_taught);
            }
        }
    }
    save_teachers();
    printf("\nTeachers sorted successfully.");
}
void marks_management(void)
{
    int choice;

    do
    {
        printf("\n\n========== MARKS MANAGEMENT ==========");
        printf("\n1. Insert Marks");
        printf("\n2. Display Marks");
        printf("\n3. Search Marks");
        printf("\n4. Update Marks");
        printf("\n5. Delete Marks");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                insert_marks();
                break;

            case 2:
                display_marks();
                break;

            case 3:
                search_marks();
                break;

            case 4:
                update_marks();
                break;

            case 5:
                delete_marks();
                break;

            case 6:
                break;

            default:
                printf("\nInvalid Input");
        }

    }while(choice != 6);
}
void insert_marks(void)
{
    m *new1, *p;
    char v;
    int cls;

    new1 = (m*)malloc(sizeof(m));

    if(new1 == NULL)
    {
        printf("\nMemory allocation failed.");
        return;
    }

    printf("\nEnter student class: ");
    scanf("%d",&cls);

    if(cls < 1 || cls > 12)
    {
        printf("\nInvalid class.");
        free(new1);
        return;
    }

    printf("\nEnter student roll number: ");
    scanf("%d",&new1->roll);

    new1->Class = cls;

    getchar();

    printf("\nEnter subject name: ");
    fgets(new1->subject,sizeof(new1->subject),stdin);
    new1->subject[strcspn(new1->subject,"\n")] = '\0';

    printf("\nEnter marks: ");
    scanf("%d",&new1->marks);

    if(new1->marks < 0 || new1->marks > 100)
    {
        printf("\nInvalid marks. Enter marks between 0 and 100.");
        free(new1);
        return;
    }

    new1->next = NULL;

    if(head_marks == NULL)
    {
        head_marks = new1;
    }
    else
    {
        p = head_marks;

        while(p->next != NULL)
        {
            p = p->next;
        }

        p->next = new1;
    }

    printf("\nMarks inserted successfully.");
    save_marks();

    printf("\nDo you want to insert marks for another subject?(y/n): ");
    scanf(" %c",&v);

    if(v == 'y' || v == 'Y')
        insert_marks();
}
void display_marks(void)
{
    int cls,r,f=0;
    m *p=head_marks;

    printf("\nEnter class: ");
    scanf("%d",&cls);

    if(cls<1 || cls>12)
    {
        printf("\nInvalid class.");
        return;
    }

    printf("\nEnter roll number: ");
    scanf("%d",&r);

    printf("\n==============================================");
    printf("\n              MARKS DETAILS");
    printf("\n==============================================");
    printf("\nClass: %d",cls);
    printf("\nRoll No: %d",r);
    printf("\n----------------------------------------------");
    printf("\n%-20s %-10s","Subject","Marks");
    printf("\n----------------------------------------------");

    while(p!=NULL)
    {
        if(p->Class==cls && p->roll==r)
        {
            printf("\n%-20s %-10d",p->subject,p->marks);
            f=1;
        }

        p=p->next;
    }

    if(f==0)
    {
        printf("\nNo marks found for this student.");
    }

    printf("\n==============================================\n");
}
void search_marks(void)
{
    m *p;
    int r, cls, f = 0;
    char v;

    printf("\nEnter student class: ");
    scanf("%d",&cls);

    if(cls < 1 || cls > 12)
    {
        printf("\nInvalid class.");
        return;
    }

    printf("\nEnter student roll number: ");
    scanf("%d",&r);

    if(head_marks == NULL)
    {
        printf("\nNo marks records found.");
        return;
    }

    p = head_marks;

    printf("\n==============================================================");
    printf("\n                         MARKS DETAILS");
    printf("\n==============================================================");

    printf("\n%-10s %-10s %-25s %-10s",
           "Class", "Roll No", "Subject", "Marks");

    printf("\n--------------------------------------------------------------");

    while(p != NULL)
    {
        if(p->Class == cls && p->roll == r)
        {
            printf("\n%-10d %-10d %-25s %-10d",
                   p->Class,
                   p->roll,
                   p->subject,
                   p->marks);

            f = 1;
        }

        p = p->next;
    }

    if(f == 0)
        printf("\nNo marks records found for this student.");
    else
        printf("\nSearch successful.");

    printf("\nDo you want to search another student?(y/n): ");
    scanf(" %c",&v);

    if(v == 'y' || v == 'Y')
        search_marks();
}
void update_marks(void)
{
    m *p;
    int r, cls, mark, f = 0;
    char sub[30];

    printf("\nEnter student class: ");
    scanf("%d",&cls);

    if(cls < 1 || cls > 12)
    {
        printf("\nInvalid class.");
        return;
    }

    printf("\nEnter student roll number: ");
    scanf("%d",&r);

    getchar();

    printf("\nEnter subject name: ");
    fgets(sub,sizeof(sub),stdin);
    sub[strcspn(sub,"\n")] = '\0';

    p = head_marks;

    while(p != NULL)
    {
        if(p->Class == cls && p->roll == r &&
           strcmp(p->subject,sub) == 0)
        {
            printf("\nEnter updated marks: ");
            scanf("%d",&mark);

            if(mark < 0 || mark > 100)
            {
                printf("\nInvalid marks.");
                return;
            }

            p->marks = mark;
            f = 1;
            break;
        }

        p = p->next;
    }

    save_marks();

    if(f == 1)
        printf("\nMarks updated successfully.");
    else
        printf("\nRecord not found.");
}
void delete_marks(void)
{
    m *p, *p1;
    int r, cls, f = 0;
    char sub[30];

    printf("\nEnter student class: ");
    scanf("%d",&cls);

    if(cls < 1 || cls > 12)
    {
        printf("\nInvalid class.");
        return;
    }

    printf("\nEnter student roll number: ");
    scanf("%d",&r);

    getchar();

    printf("\nEnter subject name: ");
    fgets(sub,sizeof(sub),stdin);
    sub[strcspn(sub,"\n")] = '\0';

    p = head_marks;

    if(p == NULL)
    {
        printf("\nNo marks records found.");
        return;
    }

    if(p->Class == cls && p->roll == r &&
       strcmp(p->subject,sub) == 0)
    {
        head_marks = p->next;
        free(p);
        f = 1;
    }
    else
    {
        p1 = p->next;

        while(p1 != NULL)
        {
            if(p1->Class == cls && p1->roll == r &&
               strcmp(p1->subject,sub) == 0)
            {
                p->next = p1->next;
                free(p1);
                f = 1;
                break;
            }

            p = p1;
            p1 = p1->next;
        }
    }

    save_marks();

    if(f == 1)
        printf("\nMarks record deleted successfully.");
    else
        printf("\nRecord not found.");
}
void load_data(void)
{
    load_students();
    load_teachers();
    load_marks();

    printf("\nRecords loaded successfully.");
}

void save_data(void)
{
    save_students();
    save_teachers();
    save_marks();
}
void load_students(void)
{
    FILE *fp;
    st *new1, *p;
    int roll, cls;
    char name[60], section;

    fp = fopen("students.txt","r");

    if(fp == NULL)
        return;

    while(fscanf(fp," %d|%59[^|]|%d|%c",
                 &roll,name,&cls,&section) == 4)
    {
        if(cls < 1 || cls > 12)
            continue;

        new1 = (st*)malloc(sizeof(st));

        if(new1 == NULL)
        {
            fclose(fp);
            return;
        }

        new1->roll = roll;
        strcpy(new1->name,name);
        new1->Class = cls;
        new1->section = section;
        new1->next = NULL;

        if(head[cls] == NULL)
            head[cls] = new1;
        else
        {
            p = head[cls];

            while(p->next != NULL)
                p = p->next;

            p->next = new1;
        }
    }

    fclose(fp);
}

void save_students(void)
{
    FILE *fp;
    st *p;
    int i;

    fp = fopen("students.txt","w");

    if(fp == NULL)
    {
        printf("\nUnable to open students.txt");
        return;
    }

    for(i = 1; i <= 12; i++)
    {
        p = head[i];

        while(p != NULL)
        {
            fprintf(fp,"%d|%s|%d|%c\n",
                    p->roll,p->name,p->Class,p->section);

            p = p->next;
        }
    }

    fclose(fp);
}
void load_teachers(void)
{
    FILE *fp;
    tr *new1, *p;
    int id;
    char name[60], classes[20];

    fp = fopen("teachers.txt","r");

    if(fp == NULL)
        return;

    while(fscanf(fp," %d|%59[^|]|%19[^\n]",
                 &id,name,classes) == 3)
    {
        new1 = (tr*)malloc(sizeof(tr));

        if(new1 == NULL)
        {
            fclose(fp);
            return;
        }

        new1->id = id;
        strcpy(new1->name,name);
        strcpy(new1->classes_taught,classes);
        new1->next = NULL;

        if(head_teacher == NULL)
            head_teacher = new1;
        else
        {
            p = head_teacher;

            while(p->next != NULL)
                p = p->next;

            p->next = new1;
        }
    }

    fclose(fp);
}

void save_teachers(void)
{
    FILE *fp;
    tr *p;

    fp = fopen("teachers.txt","w");

    if(fp == NULL)
    {
        printf("\nUnable to open teachers.txt");
        return;
    }

    p = head_teacher;

    while(p != NULL)
    {
        fprintf(fp,"%d|%s|%s\n",
                p->id,p->name,p->classes_taught);

        p = p->next;
    }

    fclose(fp);
}
void load_marks(void)
{
    FILE *fp;
    m *new1, *p;
    int roll, cls, marks;
    char subject[30];

    fp = fopen("marks.txt","r");

    if(fp == NULL)
        return;

    while(fscanf(fp," %d|%d|%29[^|]|%d",
                 &cls,&roll,subject,&marks) == 4)
    {
        if(cls < 1 || cls > 12)
            continue;

        if(marks < 0 || marks > 100)
            continue;

        new1 = (m*)malloc(sizeof(m));

        if(new1 == NULL)
        {
            fclose(fp);
            return;
        }

        new1->roll = roll;
        new1->Class = cls;
        strcpy(new1->subject,subject);
        new1->marks = marks;
        new1->next = NULL;

        if(head_marks == NULL)
            head_marks = new1;
        else
        {
            p = head_marks;

            while(p->next != NULL)
                p = p->next;

            p->next = new1;
        }
    }

    fclose(fp);
}

void save_marks(void)
{
    FILE *fp;
    m *p;

    fp = fopen("marks.txt","w");

    if(fp == NULL)
    {
        printf("\nUnable to open marks.txt");
        return;
    }

    p = head_marks;

    while(p != NULL)
    {
        fprintf(fp,"%d|%d|%s|%d\n",
                p->Class,
                p->roll,
                p->subject,
                p->marks);

        p = p->next;
    }

    fclose(fp);
}
