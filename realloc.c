#include "main.h"
/**
 * _realloc - Resizes a block of dynamic memory.
 * @old_mem_blk: Pointer to the previously allocated memory block.
 * @old_size: Size of the old memory block.
 * @new_size: Size of the new memory block.
 *
 * Description: This function adjusts the size of the memory block pointed to
 * by @old_mem_blk to match @new_size. If the new size is larger, the extra
 * memory is not initialized. If @old_mem_blk is NULL, this function behaves
 * like malloc(@new_size). If @new_size is zero and @old_mem_blk is not NULL,
 * the memory is freed and the function returns NULL.
 *
 * Return: A pointer to the newly allocated memory block, or NULL if the
 * allocation fails.
 */
void *_realloc(void *old_mem_blk, size_t old_size, size_t new_size)
{
	void *new_mem;
	size_t small_size;
	/*If the size hasn't changed, return the original memory block.*/
	if (new_size == old_size)
		return (old_mem_blk);
	/*If new_size is zero and there's an old memory block,*/
	/*free it and return NULL.*/
	if (new_size == 0 && old_mem_blk != NULL)
	{
		free(old_mem_blk);
		return (NULL);
	}
	/*Attempt to allocate a new memory block of the desired size.*/
	new_mem = malloc(new_size);
	if (new_mem == NULL)
		return (NULL); /* Return NULL if allocation fails.*/
	/*If there's an old memory block, copy its contents to the new block.*/
	if (old_mem_blk != NULL)
	{
	/*Determine the smaller of the old and new sizes to know how much to copy.*/
		small_size = (old_size < new_size) ? old_size : new_size;
		/* copy the data from old memory block to new memory block */
		_memcpy(new_mem, old_mem_blk, small_size);

		free(old_mem_blk); /* free old allocated memory block */
	}

	return (new_mem);
}
