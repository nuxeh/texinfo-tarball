/* echo-area.h -- Functions used in reading information from the echo area.
   $Id: echo-area.h 6906 2016-01-01 18:33:45Z karl $

   Copyright 1993, 1997, 2004, 2007, 2008, 2011, 2013, 2014, 2015, 2016
   Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.

   Originally written by Brian Fox. */

#ifndef INFO_ECHO_AREA_H
#define INFO_ECHO_AREA_H

#define EA_MAX_INPUT 256

extern int echo_area_is_active, info_aborted_echo_area;

/* Non-zero means that the last command executed while reading input
   killed some text. */
extern int echo_area_last_command_was_kill;

extern REFERENCE **echo_area_completion_items;

extern void inform_in_echo_area (const char *message);
extern void echo_area_inform_of_deleted_window (WINDOW *window);
extern void echo_area_prep_read (void);

typedef int (*reference_bool_fn) (REFERENCE *);

extern char *info_read_completing_internal (const char *prompt,
    REFERENCE **completions, int force, reference_bool_fn exclude);

/* Read a line of text in the echo area.  Return a malloc ()'ed string,
   or NULL if the user aborted out of this read.  PROMPT, if
   non-null, is a prompt to print before reading the line. */
extern char *info_read_in_echo_area (const char *prompt);

/* Read a line in the echo area with completion over COMPLETIONS. */
char *info_read_completing_in_echo_area (const char *prompt,
                                         REFERENCE **completions);

/* Read a line in the echo area allowing completion over COMPLETIONS, but
   not requiring it. */
extern char *info_read_maybe_completing (const char *prompt,
                                         REFERENCE **completions);

/* Read a line in the echo area with completion over COMPLETIONS, using
   EXCLUDE to exclude items from the completion list. */
char *
info_read_completing_in_echo_area_with_exclusions (const char *prompt,
    REFERENCE **completions, reference_bool_fn exclude);

extern void ea_insert (WINDOW *window, int count, int key);
extern void ea_quoted_insert (WINDOW *window, int count);
extern void ea_beg_of_line (WINDOW *window, int count);
extern void ea_backward (WINDOW *window, int count);
extern void ea_delete (WINDOW *window, int count);
extern void ea_end_of_line (WINDOW *window, int count);
extern void ea_forward (WINDOW *window, int count);
extern void ea_abort (WINDOW *window, int count);
extern void ea_rubout (WINDOW *window, int count);
extern void ea_complete (WINDOW *window, int count);
extern void ea_newline (WINDOW *window, int count);
extern void ea_kill_line (WINDOW *window, int count);
extern void ea_backward_kill_line (WINDOW *window, int count);
extern void ea_transpose_chars (WINDOW *window, int count);
extern void ea_yank (WINDOW *window, int count);
extern void ea_tab_insert (WINDOW *window, int count);
extern void ea_possible_completions (WINDOW *window, int count);
extern void ea_backward_word (WINDOW *window, int count);
extern void ea_kill_word (WINDOW *window, int count);
extern void ea_forward_word (WINDOW *window, int count);
extern void ea_yank_pop (WINDOW *window, int count);
extern void ea_backward_kill_word (WINDOW *window, int count);
extern void ea_scroll_completions_window (WINDOW *window, int count);

#endif /* not INFO_ECHO_AREA_H */
