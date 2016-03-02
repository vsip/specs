<?xml version="1.0"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
		xmlns:d="http://docbook.org/ns/docbook">

  <!-- This stylesheet can be used to strip off old or new content based on
       the revisionflag attribute -->

  <!-- 'revision' may be 'preserve', 'old', or 'new' -->
  <xsl:param name="revision" select="'preserve'"/>

  <xsl:template match="@*|node()">
    <xsl:copy>
      <xsl:apply-templates select="@*|node()"/>
    </xsl:copy>
  </xsl:template>

  <!-- Special treatment for elements containing a 'revisionflag' attribute -->
  <xsl:template match="*[@revisionflag]">
    <xsl:choose>
      <!-- In 'new' mode, preserve 'added' and 'changed' nodes, but not 'deleted'. -->
      <xsl:when test="$revision='new' and (@revisionflag='added' or @revisionflag='changed')">
	<xsl:copy>
	  <xsl:apply-templates select="@*[name() != 'revisionflag']|node()"/>
	</xsl:copy>
      </xsl:when>
      <!-- In 'old' mode, preserve 'deleted' nodes... -->
      <xsl:when test="$revision='old' and (@revisionflag='deleted')">
	<xsl:copy>
	  <xsl:apply-templates select="@*[name() != 'revisionflag']|node()"/>
	</xsl:copy>
      </xsl:when>
      <!-- ...but bail out on 'changed' content. -->
      <xsl:when test="$revision='old' and (@revisionflag='changed')">
	<xsl:message terminate="yes">Error: cannot regenerate old revision with 'changed' content.</xsl:message>
      </xsl:when>
      <!-- In 'preserve' mode, copy through everything unchanged. -->
      <xsl:when test="$revision='preserve'">
	<xsl:copy>
	  <xsl:apply-templates select="@*|node()"/>
	</xsl:copy>
      </xsl:when>
      <!-- Everything else gets stripped of.-->
      <xsl:otherwise />
    </xsl:choose>
  </xsl:template>

</xsl:stylesheet>

