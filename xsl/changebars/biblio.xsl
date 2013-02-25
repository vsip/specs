<?xml version="1.0" encoding="UTF-8"?>
<!-- Use subject to the conditions in the included file: LICENSE.bsd -->
<!-- $Id: biblio.xsl 2984 2007-05-25 10:29:10Z nigelw $ -->
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" 
                xmlns:fo="http://www.w3.org/1999/XSL/Format"  
                xmlns:d="http://docbook.org/ns/docbook"
                version="1.0">
  
  <xsl:template match="d:corpauthor | 
                       d:copyright | 
                       d:year |
                       d:holder |
                       d:corpcredit |
                       d:corpname |
                       d:date |
                       d:edition |
                       d:editor |
                       d:firstname |
                       d:honorific |
                       d:indexterm |
                       d:invpartnumber |
                       d:isbn |
                       d:issn |
                       d:issuenum |
                       d:lineage |
                       d:orgname |
                       d:othercredit |
                       d:othername |
                       d:pagenums |
                       d:printhistory |
                       d:productname |
                       d:productnumber |
                       d:pubdate |
                       d:publisher |
                       d:publishername |
                       d:pubsnumber |
                       d:releaseinfo |
                       d:revhistory |
                       d:seriesinfo |
                       d:seriesvolnums |
                       d:subtitle |
                       d:surname |
                       d:title |
                       d:titleabbrev |
                       d:volumenum |
                       d:orgdiv |
                       d:collabname |
                       d:conftitle |
                       d:confnum |
                       d:confsponsor |
                       d:bibliocoverage |
                       d:biblioid |
                       d:bibliorelation |
                       d:bibliosource |
                       d:abbrev |
                       d:abstract |
                       d:address |
                       d:affiliation |
                       d:shortaffil |
                       d:jobtitle |
                       d:artheader |
                       d:articleinfo |
                       d:artpagenums |
                       d:author |
                       d:authorblurb |
                       d:personblurb |
                       d:authorgroup |
                       d:authorinitials |
                       d:bibliomisc |
                       d:bibliomset |
                       d:biblioset |
                       d:biblioset/d:title |
                       d:biblioset/d:citetitle |
                       d:bookbiblio |
                       d:citetitle |
                       d:collab |
                       d:confgroup |
                       d:contractnum |
                       d:contractsponsor |
                       d:contrib" mode="bibliography.mode">
    <xsl:variable name="class" select="generate-id()"/>
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]">
        <fo:inline xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0">
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
  
  <xsl:template match="d:corpauthor | 
                       d:copyright | 
                       d:year |
                       d:holder |
                       d:corpcredit |
                       d:corpname |
                       d:date |
                       d:edition |
                       d:editor |
                       d:firstname |
                       d:honorific |
                       d:indexterm |
                       d:invpartnumber |
                       d:isbn |
                       d:issn |
                       d:issuenum |
                       d:lineage |
                       d:orgname |
                       d:othercredit |
                       d:othername |
                       d:pagenums |
                       d:printhistory |
                       d:productname |
                       d:productnumber |
                       d:pubdate |
                       d:publisher |
                       d:publishername |
                       d:pubsnumber |
                       d:releaseinfo |
                       d:revhistory |
                       d:seriesinfo |
                       d:seriesvolnums |
                       d:subtitle |
                       d:surname |
                       d:title |
                       d:titleabbrev |
                       d:volumenum |
                       d:orgdiv |
                       d:collabname |
                       d:conftitle |
                       d:confnum |
                       d:confsponsor |
                       d:bibliocoverage |
                       d:biblioid |
                       d:bibliorelation |
                       d:bibliosource |
                       d:abbrev |
                       d:abstract |
                       d:address |
                       d:affiliation |
                       d:shortaffil |
                       d:jobtitle |
                       d:artheader |
                       d:articleinfo |
                       d:artpagenums |
                       d:author |
                       d:authorblurb |
                       d:personblurb |
                       d:authorgroup |
                       d:authorinitials |
                       d:bibliomisc |
                       d:bibliomset |
                       d:biblioset |
                       d:biblioset/d:title |
                       d:biblioset/d:citetitle |
                       d:bookbiblio |
                       d:citetitle |
                       d:collab |
                       d:confgroup |
                       d:contractnum |
                       d:contractsponsor |
                       d:contrib" mode="bibliomixed.mode">
    <xsl:variable name="class" select="generate-id()"/>
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]">
        <fo:inline xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if the revisionflag is here and we have set them to be on -->
          <xsl:if test="$use.changebars != 0">
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