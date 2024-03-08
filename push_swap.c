#include "push_swap.h"

void print_stack_info(const Stack* stack) {
  if (stack == NULL) {
    printf("Stack is NULL\n");
    return;
  }

  printf("Stack Information:\n");
  printf("  Size: %zu\n", stack->size);

  // Check if content is allocated
  if (stack->content == NULL) {
    printf("  Content: Not allocated\n");
  } else {
    printf("  Content:\n");
    printf("    Allocated size: %zu elements\n", stack->size);
    // Avoid printing the entire content for large arrays
    if (stack->size <= 10) {
      printf("    Sample elements: ");
      for (size_t i = 0; i < stack->size; i++) {
        printf("%d ", stack->content[i]);
      }
      printf("\n");
    } else {
      printf("    Sample elements: %d ... (truncated)\n", stack->content[0]);
    }
  }
}

int main(int argc, char *argv[])
{
    Stack *stack_a;
    Stack *stack_b;
    int size;

    size = argc - 1;
    if (!size)
        return (0);
    stack_a = init_stack(size, argv, 1);
    stack_b = init_stack(size, argv, 0);
    //printf("result: %i\n", stack_a->content[0]);
    print_stack_info(stack_a);
    
    
}