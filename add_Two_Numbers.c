/*
** Adds two numbers represented as linked lists (digits in reverse order).
** Iterates through both lists, summing digits + carry (like manual addition).
** Creates a new list where each node is (sum % 10) and updates carry (sum / 10).
** Continues until both lists end and no carry remains.
**
** Example:
** l1 = [2 -> 4 -> 3] (342)
** l2 = [5 -> 6 -> 4] (465)
** result = [7 -> 0 -> 8] (807)
*/

#include <stdlib.h>

struct ListNode	*new_node(int value)
{
	struct ListNode	*node;

	node = malloc(sizeof(struct ListNode));
	if (!node)
		return (NULL);
	node->val = value;
	node->next = NULL;
	return (node);
}

struct ListNode	*addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode	*result;
	struct ListNode	*current;
	struct ListNode	*node;
	int				carry;
	int				sum;

	result = NULL;
	current = NULL;
	carry = 0;
	while (l1 || l2 || carry)
	{
		sum = carry;
		if (l1)
		{
			sum += l1->val;
			l1 = l1->next;
		}
		if (l2)
		{
			sum += l2->val;
			l2 = l2->next;
		}
		node = new_node(sum % 10);
		if (!node)
			return (result);
		carry = sum / 10;
		if (!result)
			result = node;
		else
			current->next = node;
		current = node;
	}
	return (result);
}
