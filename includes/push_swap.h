#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

/* Stack node structure */
typedef struct s_list
{
    int				content;
    int				index;
    struct s_list	*next;
}				t_list;

/* Parsing functions */
char		**args_handler(int *ac, char **av);
void		check_for_dup(t_list *stack, t_list *node);
void		check_ev(char **av, int i, int j);
void		index_init(t_list **a);
int			ft_array_len(char	**array);

/* Stack utility functions */
int			getmaxpos(t_list *stack, int max);
int			getmaxval(t_list *stack);
int			getindex(t_list **a, int index);
void		is_sorted(t_list *a, int print);

/* Sorting algorithms */
void		sort_3(t_list **stack);
void		sort_5(t_list **a, t_list **b);
void		all_sortings(t_list **a, t_list **b);

/* Stack operations */
void		sa(t_list **stack, int print);
void		sb(t_list **stack, int print);
void		ss(t_list **stack_a, t_list **stack_b, int print);
void		pa(t_list **stack_b, t_list **stack_a, int print);
void		pb(t_list **stack_a, t_list **stack_b, int print);
void		ra(t_list **stack, int print);
void		rb(t_list **stack, int print);
void		rr(t_list **stack_a, t_list **stack_b, int print);
void		rra(t_list **stack, int print);
void		rrb(t_list **stack, int print);
void		rrr(t_list **stack_a, t_list **stack_b, int print);

/* List utility functions */
t_list		*ft_lstnew(long long content);
void		ft_lstadd_back(t_list **lst, t_list *newlst);
void		ft_lstadd_front(t_list **lst, t_list *newlst);
t_list		*ft_lstlast(t_list *lst);
int			ft_lstsize(t_list *lst);
void		ft_lstclear(t_list **lst);

/* String utility functions */
char		**ft_split(char const *s, char c);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(char *s);
long long	ft_atoi(char *str);

/* Error handling */
void		error(void);
void		ft_free_array(char **array);

#endif