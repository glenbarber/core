/*
   Copyright (C) Cfengine AS

   This file is part of Cfengine 3 - written and maintained by Cfengine AS.

   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; version 3.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA

  To the extent this program is licensed as part of the Enterprise
  versions of Cfengine, the applicable Commerical Open Source License
  (COSL) may apply to this file if you as a licensee so wish it. See
  included file COSL.txt.
*/

#ifndef CFENGINE_ALPHALIST_H
#define CFENGINE_ALPHALIST_H

// Indexed itemlist
typedef struct
{
    Item *list[CF_ALPHABETSIZE];
} AlphaList;

void InitAlphaList(AlphaList *al);
int InAlphaList(AlphaList *al, const char *string);
int MatchInAlphaList(AlphaList *al, char *string);
void PrependAlphaList(AlphaList *al, const char *string);
void IdempPrependAlphaList(AlphaList *al, const char *string);
void DeleteAlphaList(AlphaList *al);
AlphaList *CopyAlphaListPointers(AlphaList *al, AlphaList *ap);
AlphaList *DupAlphaListPointers(AlphaList *ap, AlphaList *al);
void DeleteFromAlphaList(AlphaList *al, const char *string);

/*
AlphaListIterator i = AlphaListIteratorInit(&al);
Item *item;
while ((item = AlphaListIteratorNext(&i)))
   {
   // do something with item;
   }
// No cleanup is required
*/

typedef struct
{
    AlphaList *al;
    int pos;
    Item *curitem;
} AlphaListIterator;

AlphaListIterator AlphaListIteratorInit(AlphaList *al);
const Item *AlphaListIteratorNext(AlphaListIterator *iterator);

#endif
