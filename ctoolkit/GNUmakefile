# Copyright (c) 2004 - 2005, Simon Moore (simon@snmoore.net)
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
# 20050305 3       simon@snmoore.net   Arrange directory structure and configure
#                                      makefiles
# 20060518 7       simon@snmoore.net   Lint all components	       


# This is the top-level makefile that is used for all build targets, including:
#
#   all     compile all components and tests    e.g. 'gmake'
#   clean   clean all components and tests      e.g. 'gmake clean'
#   check   run the test harness                e.g. 'gmake && gmake check'
#   lint    lint all components                 e.g. 'gmake lint'
#
# It uses a recursive makefile approach to process each component, which also
# makes use of a common makefile 'GNUcommon'. This is dependent upon the
# following code layout:
#
#   GNUcommon                   common makefile used by all component makefiles
#   component/                  directory containing code for a component
#            +GNUmakefile       makefile to build this component
#            +inc/              directory containing header files (*.h)
#            +src/              directory containing source files (*.c)
#            +test/             directory containing tests for a component
#                 +GNUmakefile  makefile to build tests for this component
#                 +inc/         directory containing header files (*.h)
#                 +src/         directory containing source files (*.c)

# Specify what components and tests to build
components	:= types debug
tests		:= $(addsuffix /test,$(components)) test

# Default target; build all components and tests (using recursive make)
.PHONY: all
all: $(components) $(tests) run_all_tests

# Clean all components and tests (using recursive make)
.PHONY: clean
clean: $(components) $(tests)
	$(RM) run_all_tests run_all_tests.core

# Run the test harness (requires the 'all' target to have been built first)
# Note: this will generate a 'core' file (some tests deliberately abort)
.PHONY: check
check: run_all_tests
	./$<

# Use recursive make to build each component
.PHONY: $(components)
$(components):
	$(MAKE) --directory=$@ $(MAKECMDGOALS)

# Use recursive make to build the tests for each component
.PHONY: $(tests)
$(tests):
	$(MAKE) --directory=$@ $(MAKECMDGOALS)

# Link the tests into a test harness
run_all_tests: test/snm_test.a debug/snm_debug.a \
               types/test/snm_test_types.a debug/test/snm_test_debug.a
	$(CC) $(LDFLAGS) $? $(LOADLIBES) $(LDLIBS) -o $@

# Use recursive make to lint each component
.PHONY: lint
lint: $(components)
	$(MAKE) --directory=$< $(MAKECMDGOALS)
