#include <stdio.h>
#include <stdlib.h>

struct node {
	int coeff;
	int expo;
	struct node* link;
};

void display(struct node* head);

struct node* PHead = NULL, * QHead = NULL, * RHead;
struct node* Pptr, * Qptr, * Rptr, * ptr, * temp;
int n, i, data;

int main() {

	printf("Enter degree of first polynomial: ");
	scanf("%d", &n);
	printf("Enter coefficients of first polynomial: ");
	for (i = n; i >= 0; i--) {
		scanf("%d", &data);
		temp = (struct node*)malloc(sizeof(struct node));
		temp->coeff = data;
		temp->expo = i;
		temp->link = NULL;

		if (PHead == NULL) {
			PHead = temp;
		}
		else {
			ptr = PHead;
			while (ptr->link != NULL) {
				ptr = ptr->link;
			}
			ptr->link = temp;
		}

	}

	printf("\nP(x) = ");
	display(PHead);

	printf("enter degree of second polynomial: ");
	scanf("%d", &n);
	printf("Enter coefficients of second polynomial: ");
	for (i = n; i >= 0; i--) {
		scanf("%d", &data);
		temp = (struct node*)malloc(sizeof(struct node));
		temp->coeff = data;
		temp->expo = i;
		temp->link = NULL;

		if (QHead == NULL) {
			QHead = temp;
		}
		else {
			ptr = QHead;
			while (ptr->link != NULL) {
				ptr = ptr->link;
			}
			ptr->link = temp;
		}

	}

	printf("\nQ(x) = ");
	display(QHead);

	Pptr = PHead;
	Qptr = QHead;
	Rptr = RHead;

	while (Pptr != NULL && Qptr != NULL) {
		if (Pptr->expo == Qptr->expo) {
			temp = (struct node*)malloc(sizeof(struct node));
			temp->coeff = Pptr->coeff + Qptr->coeff;
			temp->expo = Pptr->expo;
			temp->link = NULL;

			if (RHead == NULL) {
				RHead = temp;
			}
			else {
				ptr = RHead;
				while (ptr->link != NULL) {
					ptr = ptr->link;
				}
				ptr->link = temp;
			}

			Pptr = Pptr->link;
			Qptr = Qptr->link;
		}

		if (Qptr == NULL)
            break;

		if (Pptr->expo > Qptr->expo) {
			temp = (struct node*)malloc(sizeof(struct node));
			temp->coeff = Pptr->coeff;
			temp->expo = Pptr->expo;
			temp->link = NULL;

			if (RHead == NULL) {
				RHead = temp;
			}
			else {
				ptr = RHead;
				while (ptr->link != NULL) {
					ptr = ptr->link;
				}
				ptr->link = temp;
			}

			Pptr = Pptr->link;
		}

		if (Pptr == NULL)
            break;

		if (Pptr->expo < Qptr->expo) {
			temp = (struct node*)malloc(sizeof(struct node));
			temp->coeff = Qptr->coeff;
			temp->expo = Qptr->expo;
			temp->link = NULL;

			if (RHead == NULL) {
				RHead = temp;
			}
			else {
				ptr = RHead;
				while (ptr->link != NULL) {
					ptr = ptr->link;
				}
				ptr->link = temp;
			}

			Qptr = Qptr->link;
		}

	}

	printf("\nResultant polynomial: \nR(x) = ");
	display(RHead);

	return 0;
}

void display(struct node* head) {
	ptr = head;
	while (ptr->link != NULL) {
		printf("%dx^%d + ", ptr->coeff, ptr->expo);
		ptr = ptr->link;
	}
	printf("%dx^%d\n", ptr->coeff, ptr->expo);
}