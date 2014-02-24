Build Documentation
================================================================================

The ultimate goal of "building" the specifications is to produce a PDF that
conforms to the [OMG](http://www.omg.org) specification formatting rules. The
specifications are captured in the XML-based [DocBook](http://www.docbook.org)
format. There are many ways to go about generating a PDF from the DocBook
source; one approach is described below.

This approach uses eXtensible Stylesheet Language Transformations (XSLT) to
first generate eXtensible Stylesheet Lanuage Formatting Objects (XSL-FO) from
the DockBook XML, and then use the [Apache Formatting Objects Processor]
(http://xmlgraphics.apache.org/fop/) (FOP) to process the XSL-FO and produce
a PDF.

XSLT is also used to generate eXtensible HyperText Markup Language (XHTML)
files from the DocBook XML that can later be viewed and navigated from a web
browser.

These instructions provide a snapshot of a 64-bit configuration that is known to
generate valid specification PDFs. Different configurations may work as well.
In particular, these instructions are divided into logical sub-sections.

 * Pre-requisites
   - Windows (64-bit)
   - Cygwin (64-bit)
   - Java (64-bit, 1.7-update-11)
   - Apache FOP (1.1)
   - JEuclid-FOP (stefan)
   - DocBook XSL (1.78.1)
 * Get the Specification Source
 * Generating a PDF
 
Pre-requisites
--------------------------------------------------------------------------------

These instruction assume that you already have Windows, Cygwin and Java
installed. Detailed instructions for installing the other pre-requisites are
provided below.

### Cygwin ###
 
A [Cygwin](http://www.cygwin.com)-based 64-bit Linux environment is used to
enable generating the PDF on a Windows host. The Cygwin installation must
include the following Cygwin packages. Use the Cygwin setup program
(`setup-x86_64.exe`) to install:

 * `git`
 * `libxml2` (2.9.1-1)
 * `libxslt` (1.1.28-1)
 * `make`
 * `vim`

In the case of `libxml2` and `libxslt`, a specific version is recommended; the
version is less important for the other packages.

> **NOTE**
> When installing Cygwin, use the `-B` option if you do not have administrative
> rights and want to install a user-only copy. For example, from a Windows
> command line terminal,
> 
> ```
> C:\> setup_x86_64.exe -B
> ```

### Java ###

A 64-bit version of Java must be installed on the Windows host. Java 1.7,
update 11 is recommended, but anything greater than Java 1.5 _should_ work.
Make sure that the `java` binary is on your Cygwin path; it should be by
default since it typically gets installed to `C:\Windows\system32`.

...
$ java -version
java version "1.7.0_11"
Java(TM) SE Runtime Environment (build 1.7.0_11-b21)
Java HotSpot(TM) 64-Bit Server VM (build 23.6-b04, mixed mode)
...

### Apache FOP ###

Next download and extract the binary distribution of Apache FOP 1.1 and put the
`fop` binary on your path.

```
$ wget \
http://archive.apache.org/dist/xmlgraphics/fop/binaries/fop-1.1-bin.tar.gz
$ tar xf fop-1.1-bin.tar.gz
$ echo "
PATH=\"`pwd`/fop-1.1:\${PATH}\"
export PATH" >> ~/.bash_profile
export PATH="`pwd`/fop-1.1:${PATH}"
$ fop -version
FOP Version 1.1
```

### JEuclid-FOP ###

[JEuclid](http://jeuclid.sourceforge.net/) is a plugin for FOP that provides for
Math Markup Language (MathML) redering in the generated PDF. The project is no
longer actively developed, so there is not much support, and no plans for a
new version.

According to the JEuclid website, version 3.1.9 is tightly
integrated with FOP 0.95beta or 0.95; however, you will get a nasty Java
exception during the PDF generation process if you try to use any logical
combination of the publicly-available FOP and JEuclid binary distributions.

The best guess at the problem is that either the FOP website or the JEuclid
website is inaccruate, and it takes some obscure combination of FOP and
JEuclid binary distribution versions top make this work. Another reason might be
that in order to use any of the binary distributions of FOP and JEuclid
toegther with the latest versions of Java, they must be rebuilt.

In either case, you could probably build FOP and/or JEuclid from source to
solve the problem, but, as it turns out, that is not an easy process. With all
this nonsense, Stefan was the only person who was ever able to build the
specifications. In the interest of preserving the sanity of the specification
maintainers, the version of the JEuclid FOP plugin that Stefan used to build the
specifications has been controlled and can be downloaded.

Download and extract Stefan's copy of the the JEuclid FOP plugin binary
distribution. Once extracted, add the `jeuclid-core.jar` and `jeuclid-fop.jar`
Java archives to your FOP library path.

```
$ wget \
https://drive.google.com/file/d/0B3BmMfAWYNQKeUZkVkVYeXA2Uk0/edit?usp=sharing
$ tar xf jeuclid-fop-stefan.tar.gz
$ cp jeuclid-fop-stefan/jeuclid-core.jar <YOUR_FOP1.1_DIR>/lib
$ cp jeuclid-fop-stefan/jeuclid-fop.jar <YOUR_FOP1.1_DIR>/lib
```

Replace `<YOUR_FOP1.1_DIR>` above with the location of your FOP 1.1
installation, e.g. `/cygwin/home/user/fop-1.1`.

### DocBook XSL ###

In theory, if you have an activie internet connection, you do not need to have
a local copy of the docbook XSL namespace. That being said, if you are working
without an activie connection, through a proxy, or if you just want to speed up
the "build" process, you should download a copy of the dockbook XSL namespace.

Download version 1.78.1 of the docbook XSL namespace from the
[Dockbook Project](http://docbook.sourceforge.net/) website and extract it.

```
$ wget \
http://softlayer-ams.dl.sourceforge.net/project/docbook/docbook-xsl-ns/1.78.1/docbook-xsl-ns-1.78.1.tar.bz2
$ tar xf docbook-xsl-ns-1.78.1.tar.bz2
```

Get the Specification Source
--------------------------------------------------------------------------------

Use `git` to checkout the specification "source."

```
$ git clone https://github.com/vsip/specs.git
```

If you are using a local copy of the docbook XSL namespace, you will need to
update the specification XSL files to point to your local copy instead of the
public Internet copy.

From inside the `xsl` directory at the top-level of the cloned specification
repository, change the URL for the `xhtml/chunk-changebars.xsl` import at the
top of the `xhtml.xsl` file to point to your local copy. For example,

```xml
<xsl:import href="http://docbook.sourceforge.net/release/xsl-ns/current/xhtml/chunk-changebars.xsl"/>
```

might change to

```xml
<xsl:import href="/home/user/docbook-xsl-ns-1.78.1/xhtml/chunk-changebars.xsl"/>
```

Similarly update the `fo/dockbook.xsl` import at the top of the
`changebars/changebars.xsl` file, e.g.,

```xml
<xsl:import href="http://docbook.sourceforge.net/release/xsl-ns/current/fo/docbook.xsl"/>
```

might change to

```xml
<xsl:import href="/home/user/docbook-xsl-ns-1.78.1/fo/docbook.xsl"/>
```

Generate a PDF
--------------------------------------------------------------------------------

Generating a PDF is as simple as invoking `make` from the directory
corresponding to the specification that you want to generate. For example,

```
$ cd vsipl
$ make clean; make all
```

By default the generated PDFs will not include any comments (i.e. contents
surrounded with the docbook `<remark>` tag), nor will they indicate any changed
content designated with the docbook `revisionflag` attribute. Comments and/ or
change indication can be enabled by setting the `COMMENTS` and/ or `CHANGES`
environment variables to `1`. For example, to generate PDFs both containing
comments and indicating changes,

```
$ cd vsipl
$ make clean; COMMENTS=1 CHANGES=1 make all
```

