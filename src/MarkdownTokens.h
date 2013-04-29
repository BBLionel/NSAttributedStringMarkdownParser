//
// Copyright 2012 Jeff Verkoeyen
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include <stdio.h>

typedef enum {
  MARKDOWNFIRST_TOKEN = 0x100,
  MARKDOWNEM = MARKDOWNFIRST_TOKEN,
  MARKDOWNSTRONG,
  MARKDOWNSTRONGEM,
  MARKDOWNHEADER,
  MARKDOWNMULTILINEHEADER,
  MARKDOWNURL,
  MARKDOWNHREF,
  MARKDOWNPARAGRAPH,
  MARKDOWNNEWLINE,
  MARKDOWNBULLETSTART,
  MARKDOWNUNKNOWN,

} MarkdownParserCodes;

extern const char* markdownnames[];

#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif

extern FILE *markdownin;

int markdownlex_init(yyscan_t* yyscanner);
int markdownlex_destroy(yyscan_t yyscanner);

int markdownlex(yyscan_t yyscanner);
int markdownConsume(char* text, int token, yyscan_t yyscanner);
int markdownget_lineno(yyscan_t scanner);

void* markdowngetextravar(yyscan_t yyscanner);
void markdownsetextravar(yyscan_t yyscanner, void* value);
