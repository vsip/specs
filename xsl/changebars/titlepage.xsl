<?xml version="1.0" encoding="UTF-8"?>
<!-- Use subject to the conditions in the included file: LICENSE.bsd -->
<!-- $Id: titlepage.xsl 2984 2007-05-25 10:29:10Z nigelw $ -->
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                xmlns:fo="http://www.w3.org/1999/XSL/Format"
                xmlns:d="http://docbook.org/ns/docbook"
                version="1.0">
  
  <xsl:template match="d:sidebar/d:title" mode="sidebar.title.mode">
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]"> 
        <xsl:variable name="class" select="generate-id()"/>
        <fo:inline xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:inline>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
  <xsl:template match="d:author | d:copyright | d:legalnotice" mode="titlepage.mode">
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]">
        <xsl:variable name="class" select="generate-id()"/>
        <fo:block xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the element is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:block>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>  
  </xsl:template>
  
  <xsl:template match="d:year" mode="titlepage.mode">
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]">
        <xsl:variable name="class" select="generate-id()"/>
        <fo:inline xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the element is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:inline>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>  
  </xsl:template>
  
  <xsl:template match="d:title | d:subtitle" mode="book.titlepage.recto.auto.mode">
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]"> 
        <xsl:variable name="class" select="generate-id()"/>
        <fo:block xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:block>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
  <xsl:template match="d:title | d:subtitle | d:legalnotice" mode="book.titlepage.verso.auto.mode">
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]"> 
        <xsl:variable name="class" select="generate-id()"/>
        <fo:block xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:block>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
  <xsl:template match="d:subtitle" mode="book.verso.subtitle.mode">
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]"> 
        <xsl:variable name="class" select="generate-id()"/>
        <fo:inline xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:inline>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
  <xsl:template match="d:title | d:subtitle" mode="part.titlepage.recto.auto.mode">
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]"> 
        <xsl:variable name="class" select="generate-id()"/>
        <fo:block xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:block>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
  <xsl:template match="d:title | d:subtitle | d:legalnotice" mode="part.titlepage.verso.auto.mode">
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]"> 
        <xsl:variable name="class" select="generate-id()"/>
        <fo:block xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:block>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
  <xsl:template match="d:title | d:subtitle" mode="appendix.titlepage.recto.auto.mode">
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]"> 
        <xsl:variable name="class" select="generate-id()"/>
        <fo:block xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:block>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
  <xsl:template match="d:title | d:subtitle | d:legalnotice" mode="appendix.titlepage.verso.auto.mode">
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]"> 
        <xsl:variable name="class" select="generate-id()"/>
        <fo:block xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:block>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
  <xsl:template match="d:title | d:subtitle" mode="bibliodiv.titlepage.recto.auto.mode">
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]"> 
        <xsl:variable name="class" select="generate-id()"/>
        <fo:block xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:block>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
  <xsl:template match="d:title | d:subtitle" mode="bibliodiv.titlepage.verso.auto.mode">
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]"> 
        <xsl:variable name="class" select="generate-id()"/>
        <fo:block xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:block>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
  <xsl:template match="d:title | d:subtitle" mode="chapter.titlepage.recto.auto.mode">
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]"> 
        <xsl:variable name="class" select="generate-id()"/>
        <fo:block xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:block>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
  <xsl:template match="d:title | d:subtitle | d:legalnotice" mode="chapter.titlepage.verso.auto.mode">
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]"> 
        <xsl:variable name="class" select="generate-id()"/>
        <fo:block xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:block>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
  <xsl:template match="d:title | d:subtitle" mode="bibliography.titlepage.recto.auto.mode">
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]"> 
        <xsl:variable name="class" select="generate-id()"/>
        <fo:block xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:block>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
  <xsl:template match="d:title | d:subtitle | d:legalnotice" mode="bibliography.titlepage.verso.auto.mode">
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]"> 
        <xsl:variable name="class" select="generate-id()"/>
        <fo:block xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:block>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
  <xsl:template match="d:title | d:subtitle" mode="section.titlepage.recto.auto.mode">
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]"> 
        <xsl:variable name="class" select="generate-id()"/>
        <fo:block xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:block>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
  <xsl:template match="d:title | d:subtitle | d:legalnotice" mode="section.titlepage.verso.auto.mode">
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]"> 
        <xsl:variable name="class" select="generate-id()"/>
        <fo:block xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:block>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
  <xsl:template match="d:title | d:subtitle" mode="sect1.titlepage.recto.auto.mode">
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]"> 
        <xsl:variable name="class" select="generate-id()"/>
        <fo:block xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:block>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
  <xsl:template match="d:title | d:subtitle | d:legalnotice" mode="sect1.titlepage.verso.auto.mode">
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]"> 
        <xsl:variable name="class" select="generate-id()"/>
        <fo:block xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:block>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
  <xsl:template match="d:title | d:subtitle" mode="sect2.titlepage.recto.auto.mode">
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]"> 
        <xsl:variable name="class" select="generate-id()"/>
        <fo:block xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:block>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
  <xsl:template match="d:title | d:subtitle | d:legalnotice" mode="sect2.titlepage.verso.auto.mode">
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]"> 
        <xsl:variable name="class" select="generate-id()"/>
        <fo:block xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:block>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
  <xsl:template match="d:title | d:subtitle" mode="sect3.titlepage.recto.auto.mode">
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]"> 
        <xsl:variable name="class" select="generate-id()"/>
        <fo:block xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:block>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
  <xsl:template match="d:title | d:subtitle | d:legalnotice" mode="sect3.titlepage.verso.auto.mode">
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]"> 
        <xsl:variable name="class" select="generate-id()"/>
        <fo:block xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:block>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
  <xsl:template match="d:title | d:subtitle" mode="sect4.titlepage.recto.auto.mode">
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]"> 
        <xsl:variable name="class" select="generate-id()"/>
        <fo:block xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:block>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
  <xsl:template match="d:title | d:subtitle | d:legalnotice" mode="sect4.titlepage.verso.auto.mode">
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]"> 
        <xsl:variable name="class" select="generate-id()"/>
        <fo:block xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:block>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
  <xsl:template match="d:title | d:subtitle" mode="sect5.titlepage.recto.auto.mode">
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]"> 
        <xsl:variable name="class" select="generate-id()"/>
        <fo:block xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:block>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
  <xsl:template match="d:title | d:subtitle | d:legalnotice" mode="sect5.titlepage.verso.auto.mode">
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]"> 
        <xsl:variable name="class" select="generate-id()"/>
        <fo:block xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:block>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template match="d:preface|d:chapter|d:appendix|d:bibliography|d:title|d:titleabbrev" mode="title.markup">
    <xsl:variable name="class" select="generate-id()"/>
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]"> 
        <fo:inline xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:inline>
      </xsl:when>
      <xsl:when test="child::d:title[@revisionflag='added']">
        <fo:inline xsl:use-attribute-sets='added.atts'>
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:inline>
      </xsl:when>
      <xsl:when test="child::d:title[@revisionflag='deleted']">
        <fo:inline xsl:use-attribute-sets='deleted.atts'>
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:inline>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
  <xsl:template match="d:book|d:preface|d:chapter|d:appendix" mode="titleabbrev.markup">
    <xsl:variable name="class" select="generate-id()"/>
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]"> 
        <fo:inline xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:inline>
      </xsl:when>
      <xsl:when test="child::d:title[@revisionflag='added']">
        <fo:inline xsl:use-attribute-sets='added.atts'>
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:inline>
      </xsl:when>
      <xsl:when test="child::d:title[@revisionflag='deleted']">
        <fo:inline xsl:use-attribute-sets='deleted.atts'>
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0 ">
            <fo:change-bar-end change-bar-class="{$class}"/>
          </xsl:if>
        </fo:inline>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-imports/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
</xsl:stylesheet>