# ----------------------------
# Makefile Options
# ----------------------------

NAME = CHAMPS
ICON = assets/ce/icon.png
DESCRIPTION = "Pokemon: Better Than Champions"

# ----------------------------

ARCHIVED = YES
COMPRESSED = YES
COMPRESSED_MODE = zx0

OBJDIR = $(BINDIR)/obj

# ----------------------------

CFLAGS = -Wall -Wextra -O3 -std=c17
CXXFLAGS = -Wall -Wextra -O3 -std=c++20

# ----------------------------

include $(shell cedev-config --makefile)
