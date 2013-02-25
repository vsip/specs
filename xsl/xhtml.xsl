<?xml version="1.0"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version='1.0'
		xmlns:d="http://docbook.org/ns/docbook"
		xmlns="http://www.w3.org/1999/xhtml">

<xsl:import href="http://docbook.sourceforge.net/release/xsl-ns/current/xhtml/chunk-changebars.xsl"/>

<xsl:param name="use.id.as.filename" select="1"/>
<xsl:param name="html.ext"  select="'.xhtml'"/>
<xsl:param name="html.stylesheet"  select="'style.css'"/>
<xsl:param name="use.svg" select="0"/>
<xsl:param name="navig.showtitles">1</xsl:param>
<xsl:param name="section.autolabel" select="1"/>
<xsl:param name="section.label.includes.component.label" select="1"/>
<!-- Assume document ids are stored in toplevel id attributes -->
<xsl:param name="current.docid" select="/*/@xml:id"/>
<xsl:param name="chunk.section.depth" select="0"/>
<xsl:param name="chunk.first.sections" select="0"/>
<xsl:param name="table.borders.with.css" select="1"/>

<xsl:template name="section.heading">
  <xsl:param name="section" select="."/>
  <xsl:param name="level" select="1"/>
  <xsl:param name="allow-anchors" select="1"/>
  <xsl:param name="title"/>
  <xsl:param name="class" select="'title'"/>

  <xsl:variable name="id">
    <xsl:choose>
      <!-- Make sure the subtitle doesn't get the same id as the title -->
      <xsl:when test="self::subtitle">
        <xsl:call-template name="object.id">
          <xsl:with-param name="object" select="."/>
        </xsl:call-template>
      </xsl:when>
      <!-- if title is in an *info wrapper, get the grandparent -->
      <xsl:when test="contains(local-name(..), 'info')">
        <xsl:call-template name="object.id">
          <xsl:with-param name="object" select="../.."/>
        </xsl:call-template>
      </xsl:when>
      <xsl:otherwise>
        <xsl:call-template name="object.id">
          <xsl:with-param name="object" select=".."/>
        </xsl:call-template>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:variable>

  <!-- HTML H level is one higher than section level -->
  <xsl:variable name="hlevel">
    <xsl:choose>
      <!-- highest valid HTML H level is H6; so anything nested deeper
           than 5 levels down just becomes H6 -->
      <xsl:when test="$level &gt; 5">6</xsl:when>
      <xsl:otherwise>
        <xsl:value-of select="$level + 1"/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:variable>
  <xsl:element name="h{$hlevel}" namespace="http://www.w3.org/1999/xhtml">
    <xsl:attribute name="class"><xsl:value-of select="$class"/></xsl:attribute>
    <xsl:if test="$css.decoration != '0'">
      <xsl:if test="$hlevel&lt;3">
        <xsl:attribute name="style">clear: both</xsl:attribute>
      </xsl:if>
    </xsl:if>
    <xsl:if test="$allow-anchors != 0 and $generate.id.attributes = 0">
      <xsl:call-template name="anchor">
        <xsl:with-param name="node" select="$section"/>
        <xsl:with-param name="conditional" select="0"/>
      </xsl:call-template>
    </xsl:if>
    <xsl:if test="$generate.id.attributes != 0 and not(local-name(.) = 'appendix')">
      <xsl:attribute name="id"><xsl:value-of select="$id"/></xsl:attribute>
    </xsl:if>
    <span class="title"><xsl:copy-of select="$title"/></span>
    <xsl:if test="$section/d:titleabbrev">
      <span class="titleabbrev">[<xsl:value-of select="$section/d:titleabbrev"/>]</span>
    </xsl:if>
      <span style="clear: both">&#160;</span>
  </xsl:element>
</xsl:template>

<!-- Generate appropriate spec reference labels -->

<xsl:template match="d:section" mode="xref-to">
  <xsl:param name="referrer"/>
  <xsl:param name="xrefstyle"/>
  [<xsl:value-of select="d:titleabbrev"/>]
</xsl:template>

<!-- This naming style assumes that a section has at most one 
     orderedlist child. -->
<xsl:template match="d:section/d:orderedlist/d:listitem" mode="xref-to">
  <xsl:param name="referrer"/>
  <xsl:param name="xrefstyle"/>
  [<xsl:value-of select="ancestor::d:section/d:titleabbrev"/>]/<xsl:copy-of select="count(preceding-sibling::d:listitem) + 1"/>
</xsl:template>

<xsl:template match="d:function/d:replaceable">
  <xsl:call-template name="inline.italicmonoseq"/>
</xsl:template>

</xsl:stylesheet>
