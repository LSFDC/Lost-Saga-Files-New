interface EmbedField {
  name: string;
  value: string;
  inline?: boolean;
}

interface EmbedAuthor {
  name?: string;
  url?: string;
  icon_url?: string;
}

interface EmbedFooter {
  text?: string;
  icon_url?: string;
}

interface EmbedImage {
  url?: string;
}

interface EmbedThumbnail {
  url?: string;
}

interface Embed {
  title?: string;
  description?: string;
  url?: string;
  timestamp?: Date;
  color?: number;
  author?: EmbedAuthor;
  footer?: EmbedFooter;
  image?: EmbedImage;
  thumbnail?: EmbedThumbnail;
  fields?: EmbedField[];
}

export class MessageBuilder {
  payload: {
    content: string;
    embeds: Embed[];
  };

  constructor() {
    this.payload = {
      content: "",
      embeds: [{ fields: [] }],
    };
  }

  getJSON(): { embeds: Embed[] } {
    return this.payload;
  }

  setText(text: string): this {
    this.payload.content = text;
    return this;
  }

  setAuthor(author: string, authorImage: string, authorUrl: string): this {
    this.payload.embeds[0].author = {
      name: author,
      url: authorUrl,
      icon_url: authorImage,
    };
    return this;
  }

  setTitle(title: string): this {
    this.payload.embeds[0].title = title;
    return this;
  }

  setURL(url: string): this {
    this.payload.embeds[0].url = url;
    return this;
  }

  setThumbnail(thumbnail: string): this {
    this.payload.embeds[0].thumbnail = { url: thumbnail };
    return this;
  }

  setImage(image: string): this {
    this.payload.embeds[0].image = { url: image };
    return this;
  }

  setTimestamp(date?: Date): this {
    if (date) {
      this.payload.embeds[0].timestamp = date;
    } else {
      this.payload.embeds[0].timestamp = new Date();
    }
    return this;
  }

  setColor(color: number): this {
    this.payload.embeds[0].color = color;
    return this;
  }

  setDescription(description: string): this {
    this.payload.embeds[0].description = description;
    return this;
  }

  addField(fieldName: string, fieldValue: string, inline?: boolean): this {
    this.payload.embeds[0].fields = this.payload.embeds[0].fields ?? [];
    this.payload.embeds[0].fields.push({
      name: fieldName,
      value: fieldValue,
      inline: inline ?? false,
    });
    return this;
  }

  setFooter(footer: string, footerImage: string): this {
    this.payload.embeds[0].footer = {
      text: footer,
      icon_url: footerImage,
    };
    return this;
  }
}
