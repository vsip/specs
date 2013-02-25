<?xml version="1.0" encoding="UTF-8"?>
<!-- Use subject to the conditions in the included file: LICENSE.bsd -->
<!-- $Id: autotoc.xsl 2984 2007-05-25 10:29:10Z nigelw $ -->
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" 
                xmlns:fo="http://www.w3.org/1999/XSL/Format"
                xmlns:d="http://docbook.org/ns/docbook"
                version="1.0">

  <xsl:template match="d:preface|d:chapter|d:appendix|d:article|d:part|
                       d:sect1|d:sect2|d:sect3|d:sect4|d:sect5|d:section|
                       d:bibliography|d:glossary|d:index|d:figure|d:table|
                       d:example|d:equation|d:procedure" mode="toc">
    <xsl:variable name="class" select="generate-id()"/>
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]">
        <fo:block xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 and @revisionflag">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 and @revisionflag">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:block>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
</xsl:stylesheet>