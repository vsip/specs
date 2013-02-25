<?xml version="1.0" encoding="UTF-8"?>
<!-- Use subject to the conditions in the included file: LICENSE.bsd -->
<!-- $Id: block.xsl 2984 2007-05-25 10:29:10Z nigelw $ -->
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                xmlns:fo="http://www.w3.org/1999/XSL/Format" 
                xmlns:d="http://docbook.org/ns/docbook"
                version="1.0">

  <xsl:template match="d:abstract |
                       d:abstract/d:title |
                       d:ackno | 
                       d:answer/d:*|
                       d:bibliodiv |
                       d:bibliomixed |
                       d:blockquote |
                       d:bridgehead |
                       d:callout |
                       d:calloutlist |
                       d:caption |
                       d:caution |
                       d:classsynopsis |
                       d:cmdsynopsis |
                       d:constructorsynopsis |
                       d:dedication |
                       d:deconstructorsynopsis |
                       d:epigraph |
                       d:equation |
                       d:example |
                       d:fieldsynopsis |
                       d:figure |
                       d:formalpara |
                       d:funcprototype |
                       d:funcsynopsis |
                       d:funcsynopsisinfo |
                       d:graphic |
                       d:graphicco |
                       d:highlights |
                       d:imageobjectco |
                       d:important |
                       d:informalequation |
                       d:informalexample |
                       d:informalfigure |
                       d:informaltable | 
                       d:itemizedlist | 
                       d:legalnotice |
                       d:literallayout |
                       d:mediaobject |
                       d:mediaobjectco |
                       d:member |
                       d:methodsynopsis |
                       d:msg |
                       d:msgentry |
                       d:msgexplan |
                       d:msgmain |
                       d:msgset |
                       d:note |
                       d:orderedlist |
                       d:para |
                       d:personblurb |
                       d:primaryie |
                       d:printhistory |
                       d:procedure |
                       d:programlisting |
                       d:programlistingco |
                       d:qandadiv |
                       d:qandaentry |
                       d:qandaset |
                       d:question |
                       d:refentry |
                       d:refentrytitle |
                       d:reference |
                       d:refnamediv |
                       d:refsect1 |
                       d:refsect2 |
                       d:refsect3 |
                       d:refsection |
                       d:refsynopsisdiv |
                       d:screen |
                       d:screenco |
                       d:screenshot |
                       d:secondaryie |
                       d:sect1 | 
                       d:sect2 | 
                       d:sect3 | 
                       d:sect4 | 
                       d:sect5 | 
                       d:section | 
                       d:seealsoie |
                       d:seeie |
                       d:seg |
                       d:segmentedlist |
                       d:sidebar |
                       d:simpara |
                       d:simplemsgentry |
                       d:simplelist |
                       d:simplesect |
                       d:step |
                       d:stepalternatives |
                       d:substeps |
                       d:synopfragment |
                       d:synopfragmentref |
                       d:synopsis |
                       d:table | 
                       d:task |
                       d:taskprerequisites |
                       d:taskrelated |
                       d:tasksummary |
                       d:tertiaryie |
                       d:tip |
                       d:variablelist |
                       d:warning">
    <xsl:variable name="class" select="generate-id()"/>
    <xsl:choose>
      <xsl:when test="ancestor-or-self::*[@revisionflag]">
        <fo:block xsl:use-attribute-sets="ancestor.revision.atts">
          <!-- open a changebar here if we have set them to be on -->
          <xsl:if test="$use.changebars != 0">
            <fo:change-bar-begin change-bar-class="{$class}" xsl:use-attribute-sets="changebar.atts"/>
          </xsl:if>
          <xsl:apply-imports/>
          <!-- close the changebar here if we have set them to be on -->
          <xsl:if test="$use.changebars != 0">
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