# Copyright (c) 2006, Simon Moore (simon@snmoore.net)
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
#  Redistributions of source code must retain the above copyright notice, this
#  list of conditions and the following disclaimer.
#
#  Redistributions in binary form must reproduce the above copyright notice,
#  this list of conditions and the following disclaimer in the documentation
#  and/or other materials provided with the distribution.
#
#  Neither the name of Simon Moore, snmoore.net nor the names of its
#  contributors may be used to endorse or promote products derived from this
#  software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

# History
#
# Date     Bug#    Author              Description
# ------------------------------------------------------------------------------



#
# Compilation settings
#

# Compiler language
CFLAGS		+= -std=iso9899:1999	# Use ISO C99 language mode

# Compiler warnings 
CFLAGS		+= -Wall				# Enable extra warnings
CFLAGS		+= -Wfatal-errors		# Stop at the first error
CFLAGS		+= -pedantic-errors		# Be pedantic and treat warnings as errors 

# Include paths
CPPFLAGS    +=



#
# What to build
#
sources		:= statechart.c main.c
objects		:= $(subst .c,.o,$(sources))

.PHONY: all
all: preprocess debug

preprocess: $(sources)
	$(CC) $(CFLAGS) -g $(CPPFLAGS) -DDEBUG -E $?

debug: $(objects)
	$(CC) $(CFLAGS) -g $(CPPFLAGS) -DDEBUG $? -o $@
	
.PHONY: clean
clean:
	$(RM) $(objects) debug
