/*
===========================================================================

Doom 3 BFG Edition GPL Source Code
Copyright (C) 1993-2012 id Software LLC, a ZeniMax Media company.
Copyright (C) 2014-2016 Robert Beckebans
Copyright (C) 2014-2016 Kot in Action Creative Artel

This file is part of the Doom 3 BFG Edition GPL Source Code ("Doom 3 BFG Edition Source Code").

Doom 3 BFG Edition Source Code is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Doom 3 BFG Edition Source Code is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Doom 3 BFG Edition Source Code.  If not, see <http://www.gnu.org/licenses/>.

In addition, the Doom 3 BFG Edition Source Code is also subject to certain additional terms. You should have received a copy of these additional terms immediately following the terms and conditions of the GNU General Public License which accompanied the Doom 3 BFG Edition Source Code.  If not, please request a copy in writing from id Software at the address below.

If you have questions concerning this license or the applicable additional terms, you may contact in writing id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================
*/

#ifndef __LIQUID_H__
#define __LIQUID_H__
#ifdef MOD_WATERPHYSICS		//4/5
/*
===============================================================================

  idLiquid

	Base class for all liquid object.  The entity part of the liquid is
	responsible for spawning splashes and sounds to match.

	The physics portion is as usual, responsible for the physics.
===============================================================================
*/

class idRenderModelLiquid;

class idLiquid : public idEntity {
public:
	CLASS_PROTOTYPE(idLiquid);

	void				Spawn(void);

	void				Save(idSaveGame *savefile) const;
	void				Restore(idRestoreGame *savefile);

	virtual bool		Collide(const trace_t &collision, const idVec3 &velocity);

private:
	void				Event_Touch(idEntity *other, trace_t *trace);

	idPhysics_Liquid	physicsObj;

	idRenderModelLiquid *model;

	const idDeclParticle *splash[3];
	const idDeclParticle *waves;

	idStr				smokeName;
	idStr				soundName;
};
#endif

#endif // __LIQUID_H__