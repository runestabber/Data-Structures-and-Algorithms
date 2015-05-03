/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
Function reverseBetween() takes a linklist and two points m,n between which the linklist is to be reversed.

*/
#include <iostream>
using namespace std;
ListNode* next=0;
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        
        if(!head)
           return head;
        if(m==n)
          return head;
        if(!head->next)
          return head;
        if(n==1)
        {
            next=head->next;
            return head;
        }
        ListNode * new_head=reverseBetween(head->next,m-1,n-1);
        if(m<=1)
        {
           head->next->next=head;
           head->next=next;
           return new_head;
        }
        
        if(m>1)
        {
            head->next=new_head;
            return head;
        }
        
        
        
    }
ListNode *create(ListNode *head,int data)
  {
  	if(head==NULL)
	  {
	  	head=new ListNode();
	  	head->val=data;

	  	head->next=NULL;
	  	return head;
	  }
  	else
  	{
		  ListNode *temp=head;
		  while(temp->next)
		  {
		  	temp=temp->next;
		  }
		temp->next=new node();
		temp=temp->next;
		temp->val=data;
		
		temp->next=NULL;
		return head;
	  }
  }
  
  
void display(ListNode *head)
{
	while(head)
	{
		cout<<head->val<<" ";
		head=head->next;
	}
	cout<<"\n";
	
}
  
  
int main()
    {
      ListNode *head1;
      head1=create(head1,2);

	    head1=create(head1,1);
	    head1=create(head1,9);
	    head1=create(head1,4);
	    head1=create(head1,7);
  	  head1=create(head1,3);
  	  head1=create(head1,7);
  	  display(head1);
  	  head1=reverseBetween(head1,2,5);
  	  display(head1);
    }
