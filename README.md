Introduction
------------

This repository contains the sources for the [VSIPL](
http://www.omg.org/spec/VSIPL/) and [VSIPL++](http://www.omg.org/spec/VSIPL++/)
specifications.

The specifications are written using [DocBook](http://www.docbook.org). XSLT
stylesheets are used to transform the "source code" into HTML and PDF output.

An XSL customization layer is used to fine-tune the [standard XSL stylesheets](
http://wiki.docbook.org/DocBookXslStylesheets) to produce OMG / ISO -
compliant output.

Useful references for working with DocBook are [DocBook 5: The Definitive
Guide](http://docbook.org/tdg5/en/html/docbook.html) and [DocBook XSL: The
Complete Guide](http://www.sagehill.net/docbookxsl/)

The included Make-based build system requires a UNIX shell as well as a few
build tools, such as (GNU) make, xsltproc, and fop (with the jeuclid plugin to
handle MathML), which are all freely available both in source form as well as
binaries for all major platforms.

Happy authoring !

_Stefan Seefeld_