TEX=$(shell which pdflatex) -interaction nonstopmode --shell-escape
BIBTEX=$(shell which bibtex)
SHELL=bash

NAME=main

# Find all .tex-files in current dir
FILES=$(filter %.tex, $(shell /usr/bin/find .))
TEMP_EXTS=aux log toc idx ind ilg lot lof bbl blg brf out
TEMPS=$(patsubst %.tex, %, ${FILES})

.PHONY: clean clean_all

all: ${NAME}.pdf

clean_all: clean
	if [ -e '${NAME}.pdf' ]; then rm -f ${NAME}.pdf; fi

${NAME}.pdf: ${NAME}.tex ${NAME}.bbl
	${TEX} ${NAME}.tex
	${TEX} ${NAME}.tex # to be shure of toc and links

#${NAME}.ind: ${NAME}.idx
#	makeindex ${NAME}

#${NAME}.idx: ${NAME}.tex
#	${TEX} ${NAME}.tex

${NAME}.bbl: bibliography.bib
	${TEX} ${NAME}.tex
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
figures/graph_mult.eps: ../processed_results/unsorted/cycle_timings.csv
	../scripts/gnuplot_barchart.sh -f <( awk -F , '{print $$1, $$4, $$2}' ../processed_results/unsorted/cycle_timings.csv | sort -n -k 2 ) -o eps > $@
