TEX=$(shell which pdflatex) -interaction nonstopmode --shell-escape
BIBTEX=$(shell which bibtex)
SHELL=bash

NAME=main

# Find all .tex-files in current dir
FILES=$(filter %.tex, $(shell /usr/bin/find .))
TEMP_EXTS=aux log toc idx ind ilg lot lof bbl blg brf out
TEMPS=$(patsubst %.tex, %, ${FILES})
GRAPHS=$(shell find . -name '*.tex' | xargs grep -R includegraphics | sed 's|.*figures/graph_\(.*\)\}|figures/graph_\1.eps|;tx;d;:x')

.PHONY: clean clean_all

all: ${NAME}.pdf

graphs: ${GRAPHS}

clean_all: clean
	if [ -e '${NAME}.pdf' ]; then rm -f ${NAME}.pdf; fi

${NAME}.pdf: ${NAME}.tex ${NAME}.bbl ${GRAPHS}
	${TEX} ${NAME}.tex
	${TEX} ${NAME}.tex

#${NAME}.ind: ${NAME}.idx
#	makeindex ${NAME}

#${NAME}.idx: ${NAME}.tex
#	${TEX} ${NAME}.tex

${NAME}.aux: ${NAME}.tex
	${TEX} ${NAME}.tex

${NAME}.bbl: bibliography.bib ${NAME}.aux
	${BIBTEX} ${NAME}

# Loop though all source files and remove name concated with any temp-extension
clean:
	for f in ${TEMPS}; do\
		 for ext in ${TEMP_EXTS}; do\
			rm -f $$f.$$ext;\
		done;\
	done

#
# Thought we might wanted to spellcheck the .tex-files
#
spellcheck: ${FILES}
	for f in ${FILES}; do\
		aspell -t --home-dir=. -c $$f ; \
	done

#
# Generate EPS-files
#
figures/graph_%.eps: ../processed_results/unsorted/cycle_timings.csv ./generate_figures.sh ../scripts/gnuplot_barchart.sh
	grep -R $* .| sed 's|.*width=\([^\\]*\)\\.*|\1|;tx;d;:x' | xargs ./generate_figures.sh $*
