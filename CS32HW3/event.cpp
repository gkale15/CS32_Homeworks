

class Event {
  public:
    Event(string s):m_name(s) {}
    virtual ~Event() {
    }
    virtual string name() const {
        return m_name;
    }
    virtual bool isSport() const {
        return true;
    }
    virtual string need() const = 0;

  private:
    string m_name;

};

class BasketballGame: public Event {
  public:
    BasketballGame(string s):Event(s) {}

    virtual ~BasketballGame() {
        cout << "Destroying the " <<Event::name() <<" basketball game" << endl;
    }

    virtual string need() const {
        return "hoops";
    }

};

class Concert: public Event {
  public:
    Concert(string s, string genre): Event(s), m_genre(genre) {}

    virtual ~Concert() {
        cout << "Destroying the " << Event::name() << " " << m_genre << " concert" <<endl;
    }

    virtual bool isSport() const {
        return false;
    }

    virtual string need() const {
        return "a stage";
    }

  private:
    string m_genre;
};


class HockeyGame: public Event {
  public:
    HockeyGame(string s):Event(s) {}

    virtual ~HockeyGame() {
        cout << "Destroying the " <<Event::name() <<" hockey game" << endl;
    }
    virtual string need() const {
        return "ice";
    }

};



